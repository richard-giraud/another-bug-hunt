#include <stdexcept>
#include <SDL2/SDL.h>

int main() {
    SDL_Window* window;
    bool gameIsRunning = false;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw std::runtime_error("Could not initialize SDL");
    }

    window = SDL_CreateWindow("Another Bug Hunt", 0, 0, 640, 480, 0);

    if(window == nullptr) {
        throw std::runtime_error("Could not create the window");
    }

    // Keep running until the window is closed
    gameIsRunning = true;
    while (gameIsRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    gameIsRunning = false;
                }
            }
        }
    }

    return 0;
}
