//
// Created by richardwork on 20/02/23.
//

#include <algorithm>
#include "Marines.h"

void Marines::unselectMarines() {
    auto it = begin();

    while(it != end()) {
        it->setSelected(false);
        it++;
    }
}

Marine *Marines::findMarineByClick(SDL_Point &point) {
    auto it = begin();

    while(it != end()) {
        if (it->doesClickSelect(point)) {
            return &(*it);
        }
        it++;
    }

    return nullptr;
}

Marine *Marines::findSelected() {
    auto it = begin();

    while(it != end()) {
        if (it->getSelected()) {
            return &(*it);
        }
        it++;
    }

    return nullptr;
}

void Marines::render(cairo_t *cr) {
    auto it = begin();

    while (it != end()) {
        it->render(cr);
        it++;
    }
}

void Marines::updateStatuses() {
    auto it = begin();

    while (it != end()) {
        it->updateStatus();
        it++;
    }
}