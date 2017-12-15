#pragma once

#include "../Util/Types.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Display {
public:
    Display( const int width, const int height, const std::string &title );
    void Update();
    // use hex number for color
    void Clear();
    void SetClearColor( int color );
    inline bool IsRunning() { return running; }
    inline void SetRunning( bool running ) { running = running; }
    inline void Close() { running = false; }
    //virtual ~Display();

private:
    bool running;
    SDL_Window *window;
    SDL_GLContext glContext;
    int width;
    int height;
    std::string title;
    void InitSDL();
    void InitGLEW();
};
