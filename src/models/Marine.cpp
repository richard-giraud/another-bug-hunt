//
// Created by richardwork on 20/02/23.
//

#include <cmath>

#include "Marine.h"

Marine::Marine(int x, int y) : positionX{x}, positionY{y} {}

void Marine::render(cairo_t *cr) const {
    cairo_set_source_rgba(cr, 0, 1, 0, 1);
    cairo_arc(cr, positionX, positionY, 3, 0, 2 * M_PI);
    cairo_fill(cr);
}