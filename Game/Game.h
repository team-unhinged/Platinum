#include "../Graphics/Display.h" 
#include "../Util/Types.h"
#include "Scene.h"
#include <functional>

class Game {
public:
    Game();
    inline void OnLoad( std::function<void(const Game&)> cb ) {
        load = cb;
    };
    inline void OnInput( std::function<void(const Game&)> cb ) {
        input = cb;
    }
    inline void OnUpdate( std::function<void(const Game&,float)> cb ) {
        update = cb;    
    };
    inline void OnRender( std::function<void(const Game&)> cb ) {
        render = cb;    
    };
    void Start();
    //virtual ~Game();
    
    inline Display& GetDisplay() const { return this->display; };

private:
    void Loop();
    void Load();
    void Input();
    void Update();
    void Render();
    std::function<void(const Game&)>       load;
    std::function<void(const Game&)>       input;
    std::function<void(const Game&,float)> update;
    std::function<void(const Game&)>       render;
    Display& display;
    Scene& scene;
};
