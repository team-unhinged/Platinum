#include "Entity.h"
#include <vector> // aww yis

class Scene {
    /*
     * The scene class serves to represent the internal state of the game at any given point in time
     * It contains references to all game entities
     */
public:
    Scene();

private:
    std::vector<const Entity&> entities;
};
