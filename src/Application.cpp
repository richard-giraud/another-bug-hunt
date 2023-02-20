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

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    applicationIsRunning = false;
                }
            }
        }

        this->render();
    }
}

void Application::render() {
    SDL_Surface* surface;
    SDL_Texture* texture;
    cairo_surface_t* cr_surface;
    cairo_t* cairo;

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

    // Draw the room
    if (room) {
        room->render(cairo);
    }

    // Display the rendered image
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        throw std::runtime_error("Could not create the texture");
    }
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    // Clean-up
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
