#include "Game/Game.h"
#include "Util/Types.h"
#include "Game/Player.h"
#include <iostream>

// This call back logic can be implemented into a Scene class
// which must define these functions and then pass them to the 
// Game instance to allow encapsulation of each scene/level as it's 
// own set of states.

int main () {

    /*
     * We want to define some callback functions which are then
     * registered to the Game which will execute them in the optimized game loop
     *
     * game.setLoad( lambda )
     * game.setUpdate( lambda )
     * game.setRender( lambda )
     */

    // Declare our game callbacks as lambda functions
    // All of them should take an argument of Game to be able to mutate game state.
    // The game object will pass itself into the callback funciton.
    // None of the callbacks should return anything.
    //
    // NOTE: The game object will be passed in using the 'this' keyword, which passes a pointer
    //       Therefore the lambdas defined here must take a Game * type as the first arg.
    Game g;

    g.OnLoad( [=] ( const Game& game ) {
    });

    g.OnInput( [=] ( const Game& game ) {
    });

    g.OnUpdate( [=] ( const Game& game, float dt ) { 
    });

    g.OnRender( [=] ( const Game& game ) { 
        game.GetDisplay().Clear();
        game.GetDisplay().SetClearColor( 0x00ff00ff );
    });

    // This initializes the game subsystems and creates the window,
    // calls the load callback and then starts the gameloop
    g.Start();

    return 0;
}
