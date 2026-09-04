#pragma once

#include "Sprite.h"
#include "Music.h"
#include<iostream>
using namespace std;

class State 
{
    public:
        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    private:
        Sprite bg;
        Music music;
        bool quitRequested;

};
