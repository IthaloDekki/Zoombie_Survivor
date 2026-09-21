#include "State.h"
#include "Game.h"
#include "Sprite.h"
#include "Zombie.h"

State::State()
    :   music(),
        quitRequested(false) 

{
    LoadAssets();
};

State::~State(){
    objectArray.clear();
};

void State::LoadAssets() {

    GameObject* bg = new GameObject();
    SpriteRenderer* sr = new SpriteRenderer( // background
        *bg,
        "resources/img/Background.png"
    );
    bg->AddComponent(sr);
    AddObject(bg);

    GameObject* zombieGO = new GameObject();
    zombieGO->AddComponent(new Zombie(*zombieGO)); //zombie
    zombieGO->box.x = 600;
    zombieGO->box.y = 450;
    AddObject(zombieGO);

    music.Open("resources/audio/BGM.wav"); // definir na classe Music
    music.Play();
};

void State::Update(float dt) {
    if (SDL_QuitRequested()) {
        quitRequested = true;
    };

    for (int i=0; i < (int)objectArray.size(); i++) {
        objectArray[i]->Update(dt);
    };

    for (int i=0; i < (int)objectArray.size(); i++) {
        if (objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin() + i);
            i--;
        };
    };
};

void State::Render() {
    for (int i=0; i < (int)objectArray.size(); i++) {
        objectArray[i]->Render();
    };
};

void State::AddObject(GameObject* go) {
    objectArray.emplace_back(go);
}

bool State::QuitRequested() {
    return quitRequested;
}

