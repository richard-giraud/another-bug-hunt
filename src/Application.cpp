//
// Created by richardwork on 19/02/23.
//

#include <stdexcept>

#include "Application.h"

Application::Application() {
    int initStatus = SDL_Init(SDL_INIT_EVERYTHING);

    if (initStatus != 0) {
        throw std::runtime_error("Could not initialize SDL; error code " + std::to_string(initStatus));
    }

    window = SDL_CreateWindow(screenTitle, 0, 0, screenWidth, screenHeight, screenFlags);

    if (window == nullptr) {
        throw std::runtime_error("Could not create the window");
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == nullptr) {
        throw std::runtime_error("Could not create the renderer");
    }

    room = new Room();
}

Application::~Application() {
    delete room;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Application::run() {
    applicationIsRunning = true;
    while (applicationIsRunning) {
        SDL_Event event;
        SDL_Surface* surface;
        SDL_Texture* texture;
        cairo_surface_t* cr_surface;
        cairo_t* cairo;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    applicationIsRunning = false;
                }
            }
        }

        surface = SDL_CreateRGBSurface(
                0,
                screenWidth, screenHeight, 32,
                0x00ff0000, 0x0000ff00, 0x000000ff, 0
        );

        if (surface == nullptr) {
            throw std::runtime_error("Could not create the RGB surface");
        }

        cr_surface = cairo_image_surface_create_for_data(
                (unsigned char*)surface->pixels,
                CAIRO_FORMAT_RGB24,
                surface->w,
                surface->h,
                surface->pitch
        );

        cairo = cairo_create(cr_surface);
        cairo_set_source_rgba(cairo, 1, 1, 1, 1.0);

        if (room) {
            room->render(cairo);
        }

        texture = SDL_CreateTextureFromSurface(renderer, surface);

        if (texture == nullptr) {
            throw std::runtime_error("Could not create the texture");
        }

        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture);

        SDL_FreeSurface(surface);
    }
}
