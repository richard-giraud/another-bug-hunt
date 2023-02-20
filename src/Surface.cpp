//
// Created by richardwork on 20/02/23.
//

#include <stdexcept>

#include "Surface.h"

Surface::Surface(int screenWidth, int screenHeight) {
    // Allocate memory for Cairo to draw to
    surface = SDL_CreateRGBSurface(
            0,
            screenWidth, screenHeight, 32,
            0x00ff0000, 0x0000ff00, 0x000000ff, 0
    );
    if (surface == nullptr) {
        throw std::runtime_error("Could not create the RGB surface");
    }

    // Initialize the Cairo instance
    cr_surface = cairo_image_surface_create_for_data(
            (unsigned char*)surface->pixels,
            CAIRO_FORMAT_RGB24,
            surface->w,
            surface->h,
            surface->pitch
    );
    cairo = cairo_create(cr_surface);
}

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

void Surface::renderCopy(SDL_Renderer* renderer) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (texture == nullptr) {
        throw std::runtime_error("Could not create the texture");
    }

    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    SDL_DestroyTexture(texture);
}

cairo_t *Surface::getCairo() {
    return cairo;
}