#include "Game.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


Game* Game::instance = nullptr;

Game::Game(string title, int width, int height){
    if(instance != nullptr){
        throw std::runtime_error("Game instance already exists");
    };

    instance = this;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        throw std::runtime_error(SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) !=
        (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF))
    {
        throw std::runtime_error(IMG_GetError());
    }

    if (Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG)
    {
        throw std::runtime_error(Mix_GetError());
    }

    if (Mix_OpenAudio(
            MIX_DEFAULT_FREQUENCY,
            MIX_DEFAULT_FORMAT,
            MIX_DEFAULT_CHANNELS,
            1024) != 0)
    {
        throw std::runtime_error(Mix_GetError());
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );

    if (window == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (renderer == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }

    state = new State();
};

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
};

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
};

void Game::Run(){
    while(!state->QuitRequested()){
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
};

Game& Game::GetInstance(){
    if(instance != nullptr){
        return *instance;
    };

    instance = new Game("Zoombie", 1024, 600);

    return *instance;

};