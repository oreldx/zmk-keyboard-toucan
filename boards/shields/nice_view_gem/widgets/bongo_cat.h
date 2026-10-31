#pragma once

#include <lvgl.h>
#include "util.h"

/**
 * Bongo cat shown on every layer, above the active layer name, with a variant per layer.
 * Each key press slams the paw on the same side as the pressed key; the cat
 * goes back to idle after BONGO_CAT_IDLE_DELAY_MS without key presses.
 */
#define BONGO_CAT_IDLE_DELAY_MS 150

enum bongo_cat_frame {
    BONGO_CAT_FRAME_IDLE,
    BONGO_CAT_FRAME_LEFT,  /* key pressed on the left half */
    BONGO_CAT_FRAME_RIGHT, /* key pressed on the right half */
    BONGO_CAT_FRAME_COUNT,
};

struct bongo_cat_sprite {
    const lv_img_dsc_t *img;
    lv_coord_t x, y; /* position on the screen */
};

/* Frames generated from assets/bongo_cat/<variant>_<frame>.png by assets/bongo_cat/generate.py */
struct bongo_cat_variant {
    struct bongo_cat_sprite frames[BONGO_CAT_FRAME_COUNT];
};

/* Toucan keymap positions: 3 rows of 6+6 keys, then 3+3 thumb keys */
#define BONGO_CAT_KEYS_PER_ROW 12
#define BONGO_CAT_THUMB_ROW_START 36
#define BONGO_CAT_THUMB_KEYS 6

void draw_bongo_cat(lv_obj_t *canvas, const struct status_state *state);

/** Whether a keymap position belongs to the left half of the keyboard. */
bool bongo_cat_position_is_left(uint32_t position);

/** Slam the paw matching the keyboard half that was pressed. */
void bongo_cat_show_tap(bool left);

/** Go back to the idle frame (both paws up). */
void bongo_cat_show_idle(void);
