#include "State.h"
#include "Game.h"
#include "Sprite.h"

State::State()
    :   bg(),
        music(),
        quitRequested(false) 

{
    LoadAssets();
};


void State::LoadAssets() {
    bg.Open("resources/img/Background.png"); // definir na classe Sprite
    music.Open("resources/audio/BGM.wav"); // definir na classe Music
    music.Play();
};

void State::Update(float dt) {
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
};

void State::Render() {
    bg.Render(0,0);
};

bool State::QuitRequested() {
    return quitRequested;
}

