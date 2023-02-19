#include <stdexcept>
#include <SDL2/SDL.h>

#include "src/Application.h"

int main() {
    auto* application = new Application();
    application->run();
    delete application;
    return 0;
}
