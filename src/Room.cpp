//
// Created by richardwork on 19/02/23.
//

#include "Room.h"

Room::Room() {
    positionX = 20;
    positionY = 20;

    height = 40;
    width = 50;
}

void Room::render(cairo_t *cr) const {
    cairo_set_source_rgba(cr, 1, 0, 0, 1);
    cairo_rectangle(
            cr,
            positionX, positionY,
            width, height
    );
    cairo_fill(cr);
    cairo_set_source_rgba(cr, 0, 0, 0.5, 1);
    cairo_rectangle(
            cr,
            positionX + 2, positionY + 2,
            width - 4, height - 4
    );
    cairo_fill(cr);
}