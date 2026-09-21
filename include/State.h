#pragma once

#include "SpriteRenderer.h"
#include "Music.h"
#include "GameObject.h"
#include <vector>
#include <memory>
using namespace std;

class State 
{
    public:
        State();
        ~State();
        void AddObject(GameObject* go);
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    private:
        Music music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;

};
