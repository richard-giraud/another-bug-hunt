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

    SDL_Point *movingTo = nullptr;
    const float movingSpeed = 1.0;

public:
    Marine(int x, int y);
    ~Marine();

    void render(cairo_t *cr) const;

    bool doesClickSelect(SDL_Point &point) const;

    [[nodiscard]] bool getSelected() const;

    void setSelected(bool value);

    void moveTo(SDL_Point &point);

    void updateStatus();
};


#endif //ANOTHER_BUG_HUNT_MARINE_H
