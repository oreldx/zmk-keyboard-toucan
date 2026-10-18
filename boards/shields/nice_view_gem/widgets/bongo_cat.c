#include <zephyr/kernel.h>
#include <zmk/keymap.h>

#include "bongo_cat.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bongo_cat_idle);
LV_IMG_DECLARE(bongo_cat_left);
LV_IMG_DECLARE(bongo_cat_right);

enum bongo_cat_frame {
    BONGO_CAT_FRAME_IDLE,
    BONGO_CAT_FRAME_LEFT,
    BONGO_CAT_FRAME_RIGHT,
};

static enum bongo_cat_frame current_frame = BONGO_CAT_FRAME_IDLE;
static bool next_paw_left = true;

void bongo_cat_tap(void) {
    current_frame = next_paw_left ? BONGO_CAT_FRAME_LEFT : BONGO_CAT_FRAME_RIGHT;
    next_paw_left = !next_paw_left;
}

void bongo_cat_idle(void) { current_frame = BONGO_CAT_FRAME_IDLE; }

void draw_bongo_cat(lv_obj_t *canvas, const struct status_state *state) {
    const lv_img_dsc_t *frame;
    switch (current_frame) {
    case BONGO_CAT_FRAME_LEFT:
        frame = &bongo_cat_left;
        break;
    case BONGO_CAT_FRAME_RIGHT:
        frame = &bongo_cat_right;
        break;
    default:
        frame = &bongo_cat_idle;
        break;
    }

    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    // Center the cat horizontally, between the batteries (y <= 27) and the layer name
    lv_canvas_draw_img(canvas, (SCREEN_WIDTH - frame->header.w) / 2, 32, frame, &img_dsc);

    // Keep the layer name visible in small text under the cat
    const char *layer_name = zmk_keymap_layer_name(zmk_keymap_layer_index_to_id(state->layer_index));
    if (layer_name != NULL && layer_name[0] != '\0') {
        lv_draw_label_dsc_t label_dsc;
        init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_CENTER);
        lv_canvas_draw_text(canvas, 0, 122, SCREEN_WIDTH, &label_dsc, layer_name);
    }
}
