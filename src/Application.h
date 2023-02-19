//
// Created by richardwork on 19/02/23.
//

#ifndef ANOTHER_BUG_HUNT_APPLICATION_H
#define ANOTHER_BUG_HUNT_APPLICATION_H

#include <string>
#include <SDL2/SDL.h>

class Application {
private:
    inline static const int screenHeight = 480;
    inline static const int screenWidth = 640;
    inline static const char screenTitle[] = "Another Bug Hunt";
    inline static const int screenFlags = 0;

    SDL_Window* window;
    bool applicationIsRunning = false;
public:
    Application();
    ~Application();
    void run();
};


#endif //ANOTHER_BUG_HUNT_APPLICATION_H
