#include <zephyr/kernel.h>
#include <stdio.h>
#include <string.h>
#include <zmk/keymap.h>

#include "bongo_cat.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(apple_logo);

extern const struct bongo_cat_variant bongo_cat_variant_base;
extern const struct bongo_cat_variant bongo_cat_variant_spec;
extern const struct bongo_cat_variant bongo_cat_variant_wheel;
extern const struct bongo_cat_variant bongo_cat_variant_mouse;
extern const struct bongo_cat_variant bongo_cat_variant_debug;

// Variant per layer display-name (without the "_MAC" suffix); other layers get the base cat
static const struct {
    const char *layer;
    const struct bongo_cat_variant *variant;
} layer_variants[] = {
    {"SPEC", &bongo_cat_variant_spec},
    {"NUM", &bongo_cat_variant_wheel},  // arrows: the cat steers a ship wheel
    {"NAV", &bongo_cat_variant_mouse},  // mouse buttons: the cat chases a mouse
    {"DEBUG", &bongo_cat_variant_debug},
};

// Layers whose display-name ends with this suffix get an Apple logo instead
#define MAC_LAYER_SUFFIX "_MAC"
#define APPLE_LOGO_GAP 3

static enum bongo_cat_frame current_frame = BONGO_CAT_FRAME_IDLE;

bool bongo_cat_position_is_left(uint32_t position) {
    if (position < BONGO_CAT_THUMB_ROW_START) {
        return position % BONGO_CAT_KEYS_PER_ROW < BONGO_CAT_KEYS_PER_ROW / 2;
    }
    return position < BONGO_CAT_THUMB_ROW_START + BONGO_CAT_THUMB_KEYS / 2;
}

void bongo_cat_show_tap(bool left) {
    current_frame = left ? BONGO_CAT_FRAME_LEFT : BONGO_CAT_FRAME_RIGHT;
}

void bongo_cat_show_idle(void) { current_frame = BONGO_CAT_FRAME_IDLE; }

static const struct bongo_cat_variant *variant_for_layer(const char *layer_name) {
    for (size_t i = 0; i < ARRAY_SIZE(layer_variants); i++) {
        if (strcmp(layer_name, layer_variants[i].layer) == 0) {
            return layer_variants[i].variant;
        }
    }
    return &bongo_cat_variant_base;
}

void draw_bongo_cat(lv_obj_t *canvas, const struct status_state *state) {
    char layer_name_buf[16];
    const char *layer_name = zmk_keymap_layer_name(zmk_keymap_layer_index_to_id(state->layer_index));
    if (layer_name == NULL || layer_name[0] == '\0') {
        sprintf(layer_name_buf, "L#%" PRIu8, state->layer_index);
        layer_name = layer_name_buf;
    }

    // "BASE_MAC" is shown as "<apple> BASE"
    bool is_mac_layer = false;
    size_t name_len = strlen(layer_name);
    size_t suffix_len = strlen(MAC_LAYER_SUFFIX);
    if (name_len > suffix_len && name_len - suffix_len < sizeof(layer_name_buf) &&
        strcmp(layer_name + name_len - suffix_len, MAC_LAYER_SUFFIX) == 0) {
        memmove(layer_name_buf, layer_name, name_len - suffix_len);
        layer_name_buf[name_len - suffix_len] = '\0';
        layer_name = layer_name_buf;
        is_mac_layer = true;
    }

    // Frames sit between the batteries (y <= 27) and the layer name (y >= 122)
    const struct bongo_cat_sprite *sprite = &variant_for_layer(layer_name)->frames[current_frame];
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    lv_canvas_draw_img(canvas, sprite->x, sprite->y, sprite->img, &img_dsc);

    // Keep the layer name visible in small text under the cat
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);

    lv_point_t text_size;
    lv_txt_get_size(&text_size, layer_name, label_dsc.font, label_dsc.letter_space,
                    label_dsc.line_space, LV_COORD_MAX, LV_TEXT_FLAG_NONE);

    lv_coord_t total_width = text_size.x;
    if (is_mac_layer) {
        total_width += apple_logo.header.w + APPLE_LOGO_GAP;
    }
    lv_coord_t x = (SCREEN_WIDTH - total_width) / 2;

    if (is_mac_layer) {
        // Sit the logo on the text baseline
        lv_coord_t logo_y = 122 + label_dsc.font->line_height - label_dsc.font->base_line -
                            apple_logo.header.h;
        lv_canvas_draw_img(canvas, x, logo_y, &apple_logo, &img_dsc);
        x += apple_logo.header.w + APPLE_LOGO_GAP;
    }

    lv_canvas_draw_text(canvas, x, 122, text_size.x + 1, &label_dsc, layer_name);
}
