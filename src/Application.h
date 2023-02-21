//
// Created by richardwork on 19/02/23.
//

#ifndef ANOTHER_BUG_HUNT_APPLICATION_H
#define ANOTHER_BUG_HUNT_APPLICATION_H

#include <string>

#include <cairo/cairo.h>
#include <SDL2/SDL.h>

#include "models/Marine.h"
#include "models/Room.h"

class Application {
private:
    inline static const int screenHeight = 480;
    inline static const int screenWidth = 640;
    inline static const char screenTitle[] = "Another Bug Hunt";
    inline static const int screenFlags = 0;
    inline static const int framesPerSecond = 60;

    SDL_Window *window;
    SDL_Renderer *renderer;

    bool applicationIsRunning = false;
    u_int64_t frameStart = 0;
    Marine *marine1 = nullptr;
    Marine *marine2 = nullptr;
    Room *room = nullptr;

    void startFrame();

    void render();

    void waitForNextFrame() const;

    void handleMouseClick(const SDL_MouseButtonEvent &event);

public:
    Application();

    ~Application();

    void run();
};


#endif //ANOTHER_BUG_HUNT_APPLICATION_H
