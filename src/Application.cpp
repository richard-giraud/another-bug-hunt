//
// Created by richardwork on 19/02/23.
//

#include <chrono>
#include <stdexcept>

#include "Application.h"
#include "Surface.h"

using namespace std::chrono;

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
        this->startFrame();
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    applicationIsRunning = false;
                }
            }
        }

        this->render();
        this->waitForNextFrame();
    }
}

void Application::startFrame() {
    this->frameStart = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void Application::waitForNextFrame() const {
    u_int64_t current = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    u_int64_t elapsed = current - this->frameStart;
    u_int64_t frameLength = (1000 / Application::framesPerSecond);

    // This enforces the maximum FPS.  If it starts taking more than the allocated time, it will slow down.
    if (frameLength > elapsed) {
        u_int64_t remainder = frameLength - elapsed;
        SDL_Delay(remainder);
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
