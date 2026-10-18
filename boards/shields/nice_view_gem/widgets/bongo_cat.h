#pragma once

#include <lvgl.h>
#include "util.h"

/**
 * Bongo cat shown in place of the layer name on base layers.
 * Each key press slams the next paw down; the cat goes back to idle
 * after BONGO_CAT_IDLE_DELAY_MS without key presses.
 */
#define BONGO_CAT_IDLE_DELAY_MS 150

void draw_bongo_cat(lv_obj_t *canvas, const struct status_state *state);

/** Switch to the next paw frame (alternates left/right). */
void bongo_cat_tap(void);

/** Go back to the idle frame (both paws up). */
void bongo_cat_idle(void);
