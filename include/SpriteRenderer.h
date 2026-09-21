#pragma once
#include "Component.h"
#include "Sprite.h"
#include <string>
#include <iostream>

using namespace std;

class SpriteRenderer : public Component {
    public:
        SpriteRenderer(GameObject& associated);
        SpriteRenderer(
            GameObject& associated,
            string file,
            int frameCountW = 1,
            int frameCountH = 1
        );
        void Open(string file);
        void SetFrameCount(int frameCountW, int frameCountH);
        void Update(float dt);
        void Render();
        void SetFrame(int frame);
    private:
        Sprite sprite;
};