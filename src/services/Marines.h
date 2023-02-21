//
// Created by richardwork on 20/02/23.
//

#ifndef ANOTHER_BUG_HUNT_MARINES_H
#define ANOTHER_BUG_HUNT_MARINES_H

#include <list>

#include <cairo/cairo.h>

#include "../models/Marine.h"

class Marines : public std::list<Marine> {
public:
    void unselectMarines();

    Marine *findMarineByClick(SDL_Point &point);

    Marine *findSelected();

    void render(cairo_t *cr);

    void updateStatuses();
};


#endif //ANOTHER_BUG_HUNT_MARINES_H
