//
// Created by richardwork on 20/02/23.
//

#ifndef ANOTHER_BUG_HUNT_SURFACE_H
#define ANOTHER_BUG_HUNT_SURFACE_H

#include <cairo/cairo.h>
#include <SDL2/SDL.h>

class Surface {
private:
    SDL_Surface *surface;
    cairo_surface_t *cr_surface;
    cairo_t *cairo;
public:
    Surface(int screenWidth, int screenHeight);

    ~Surface();

    void renderCopy(SDL_Renderer *renderer);

    cairo_t *getCairo();
};

#endif //ANOTHER_BUG_HUNT_SURFACE_H
