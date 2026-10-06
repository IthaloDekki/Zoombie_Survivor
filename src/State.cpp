#include "State.h"
#include "Game.h"
#include "Sprite.h"
#include "Zombie.h"
#include "TileMap.h"
#include "TileSet.h"

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

    GameObject* mapGO = new GameObject();
    TileSet* tileSet = new TileSet(
        64,
        64,
        "resources/img/Tileset.png"
    );

    mapGO->AddComponent(
        new TileMap(
            *mapGO,
            "resources/map/map.txt",
            tileSet
        )
    );
    mapGO->box.x = 0;
    mapGO->box.y = 0;

    AddObject(mapGO);

    GameObject* zombieGO = new GameObject();
    zombieGO->AddComponent(new Zombie(*zombieGO));
    zombieGO->box.x = 600;
    zombieGO->box.y = 450;
    AddObject(zombieGO);


    GameObject* zombieGO2 = new GameObject();
    zombieGO2->AddComponent(new Zombie(*zombieGO2));
    zombieGO2->box.x = 300;
    zombieGO2->box.y = 200;
    AddObject(zombieGO2);


    GameObject* zombieGO3 = new GameObject();
    zombieGO3->AddComponent(new Zombie(*zombieGO3));
    zombieGO3->box.x = 900;
    zombieGO3->box.y = 300;
    AddObject(zombieGO3);

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

