//
// Created by richardwork on 19/02/23.
//

#include <stdexcept>

#include "Application.h"
#include "Surface.h"

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
    Surface fr = Surface(screenWidth, screenHeight);

    // Draw the room
    if (room) {
        room->render(fr.getCairo());
    }

    fr.renderCopy(renderer);

    SDL_RenderPresent(renderer);
}
