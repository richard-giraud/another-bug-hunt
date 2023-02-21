//
// Created by richardwork on 20/02/23.
//

#include <algorithm>
#include "Marines.h"

void Marines::selectMarineByClick(SDL_Point &point) {
    std::list<Marine>::iterator it;

    Marine *selected = nullptr;

    for (it = begin(); it != end(); it++) {
        Marine *marine = &(*it);
        if (marine->doesClickSelect(point)) {
            selected = marine;
        }
        marine->setSelected(false);
    }

    if (selected) {
        selected->setSelected(true);
    }
}

void Marines::render(cairo_t *cr) {
    auto it = begin();

    while (it != end()) {
        it->render(cr);
        it++;
    }
}