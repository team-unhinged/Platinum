#include "Display.h"
#include <iostream>
#include <GL/glew.h>

Display::Display( const int width, const int height, const std::string &title ) {
    this->width = width;
    this->height = height;
    this->title = title;

    InitSDL();
    //Create the SDL window
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );
    glContext = SDL_GL_CreateContext( window );
    if ( glContext == NULL ) {
        std::cout << "Error could not initialize GL context" << std::endl; 
        running = false;
    }
    InitGLEW();
    glViewport( 0, 0, width, height );
    glEnable( GL_TEXTURE_2D );
    glEnable( GL_ALPHA_TEST );
    SetClearColor( 0x000000ff );
    running = true;
}

void Display::Update() {
    // double buffer and such
    SDL_GL_SwapWindow( window );
}

void Display::Clear() {
    glClear( GL_COLOR_BUFFER_BIT );
}

void Display::SetClearColor ( int color ) {

    float r, g, b, a;

    r = (float) ( (color >> 24 ) & 0xff);
    g = (float) ( (color >> 16 ) & 0x00ff);
    b = (float) ( (color >> 8 )  & 0x0000ff);
    a = (float) ( (color >> 0 )  & 0x000000ff);

    glClearColor( r / 0xff, g / 0xff, b / 0xff, a / 0xff );

}

void Display::InitSDL() {
    if (SDL_Init( SDL_INIT_EVERYTHING ) != 0) {
        SDL_Log("Unable to initialize SDL subsystems: %s", SDL_GetError());
        running = false;
    }

    if (IMG_Init( IMG_INIT_PNG ) != 0) {
        SDL_Log("Unable to initialize SDL IMG PNG: %s", SDL_GetError());
        running = false;
    }

    // Setup some more SDL params
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

}

void Display::InitGLEW() {
    GLenum err = glewInit();
    if ( GLEW_OK != err ) {
        // couldn't wrangle that wild OpenGL
        std::cout << "Unable to initialized GLEW: " << glewGetErrorString( err ) << std::endl;
        running = false;
    }
}
