//
// Created by richardwork on 19/02/23.
//

#ifndef ANOTHER_BUG_HUNT_ROOM_H
#define ANOTHER_BUG_HUNT_ROOM_H

#include <cairo/cairo.h>
#include <SDL2/SDL.h>

class Room {
private:
    int positionX;
    int positionY;
    int height;
    int width;
public:
    Room();

    void render(cairo_t *cr) const;
};


#endif //ANOTHER_BUG_HUNT_ROOM_H
