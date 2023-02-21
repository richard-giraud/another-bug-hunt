//
// Created by richardwork on 20/02/23.
//

#include <cmath>

#include "Marine.h"

Marine::Marine(int x, int y) : positionX{x}, positionY{y} {}

void Marine::render(cairo_t *cr) const {
    if (isSelected) {
        cairo_set_source_rgba(cr, 1, 1, 0, 1);
        cairo_set_line_width(cr, 4);
        cairo_arc(cr, positionX, positionY, 4, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);

        cairo_set_source_rgba(cr, 0, 0, 0, 1);
        cairo_fill(cr);
    }

    cairo_set_source_rgba(cr, 0, 1, 0, 1);
    cairo_arc(cr, positionX, positionY, 3, 0, 2 * M_PI);
    cairo_fill(cr);
}

bool Marine::doesClickSelect(SDL_Point &point) const {
    double hComponent = pow(point.x - positionX, 2);
    double vComponent = pow(point.y - positionY, 2);
    double distance = sqrt(hComponent + vComponent);

    bool isClicked = distance <= selectRadius;

    return isClicked;
}

void Marine::setSelected(bool value) {
    isSelected = value;
}