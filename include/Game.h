#include <SDL2/SDL.h>
#include "State.h"
#include <iostream>

using namespace std;

class Game 
{
    string title;
    int width;
    int height;

    private:
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;

        Game(string title, int width, int height);

    public: 
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        static Game& GetInstance();

};