#include "Game.h"
#include "Renderer.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#define MS_PER_FRAME 16 // the number of ms we have to do our processing each frame

Game::Game() {
}

void Game::Loop() {
    // see the gameprogrammingpatterns book on game loops
    bool running = true;
    // The optimized game loop
    // locked to 60fps
    // we can simply run the calculations then sleep until it's time to 
    // loop again. 
    //
    // In the future we can also consider the more complex but arguably better
    // technique of having a fixed timestep for updates and a variable step for rendering
    // coupled with rendering extrapolation.
    while ( display->IsRunning() ) {
        // Should use SDL_GetPerformanceFrequeny and SDL_GetPerformanceTicks
        Uint32 start = SDL_GetTicks(); // get the number of MS ellapsed since SDL started
        this->Input();
        this->Update();
        this->Render();

        // wait til we need to update again, this is capped at 60fps but the game may slow down
        // if it cannot run at 60fps.
        Uint32 elapsed = start + MS_PER_FRAME - SDL_GetTicks();
        std::cout << "Elapsed: " << elapsed << std::endl;
        SDL_Delay( start + MS_PER_FRAME - SDL_GetTicks() );
    }
}

void Game::Load() {
    // preliminary work

    // call the load callback
    load( *this );
}

void Game::Input() {
    // preliminary work
    
    // call the input callback
    input( *this );
}

void Game::Update() {
    // preliminary work

    // call the update callback
    GLfloat dt = 0.0f;
    update( *this, dt );
}

void Game::Render() {
    // preliminary work
    
    // call the render callback
    render( *this );
    // double buffer the window
    this->display->Update();
}

void Game::Start() {
    // create the display and such first
    display = new Display( 800, 600, "Test Game: Plat" );
    // call the load function to set up game stuff.
    // level, entities, etc. 
    this->Load();
    // start the game loop
    Loop();
}
