#pragma once

#include <lvgl.h>
#include "util.h"

struct layer_status_state {
    uint8_t index;
};

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state);

/** True when the active layer's display-name starts with "BASE" (BASE, BASE_MAC, ...). */
bool is_base_layer(const struct status_state *state);