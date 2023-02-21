//
// Created by richardwork on 20/02/23.
//

#ifndef ANOTHER_BUG_HUNT_MARINE_H
#define ANOTHER_BUG_HUNT_MARINE_H

#include <cairo/cairo.h>
#include <SDL2/SDL.h>

class Marine {
private:
    int positionX;
    int positionY;

    bool isSelected = false;
    // How close does a click need to be to select it
    float selectRadius = 2.0;
public:
    Marine(int x, int y);

    void render(cairo_t *cr) const;

    bool doesClickSelect(SDL_Point &point) const;

    void setSelected(bool value);
};


#endif //ANOTHER_BUG_HUNT_MARINE_H
