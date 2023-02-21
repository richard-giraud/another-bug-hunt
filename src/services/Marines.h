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
    void selectMarineByClick(SDL_Point &point);

    void render(cairo_t *cr);
};


#endif //ANOTHER_BUG_HUNT_MARINES_H
