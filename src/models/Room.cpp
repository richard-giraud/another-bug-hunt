//
// Created by richardwork on 19/02/23.
//

#include "Room.h"

Room::Room(int x, int y, int w, int h) : positionX{x}, positionY{y}, width{w}, height{h} {}

void Room::render(cairo_t *cr) const {
    cairo_set_source_rgba(cr, 0.75, 0.75, 0.75, 1);
    cairo_set_line_width(cr, 4);
    cairo_rectangle(
            cr,
            positionX, positionY,
            width, height
    );
    cairo_stroke_preserve(cr);

    cairo_set_source_rgba(cr, 0, 0, 0, 1);
    cairo_fill(cr);
}