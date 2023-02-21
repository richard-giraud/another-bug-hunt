//
// Created by richardwork on 20/02/23.
//

#ifndef ANOTHER_BUG_HUNT_MARINE_H
#define ANOTHER_BUG_HUNT_MARINE_H

#include <cairo/cairo.h>

class Marine {
private:
    int positionX;
    int positionY;
public:
    Marine();

    void render(cairo_t *cr) const;
};


#endif //ANOTHER_BUG_HUNT_MARINE_H
