#pragma once
#include "Component.h"
#include "Animation.h"
#include <string>
#include <unordered_map>
using namespace std;

class Animator : public Component {
    public:
        Animator(GameObject& associated);
        void Update(float dt);
        void Render();
        void SetAnimation(string name);
        void AddAnimation(string name, Animation anim);

    private:
        unordered_map<string, Animation> animations;
        int frameStart;
        int frameEnd;
        float frameTime;
        int currentFrame;
        float timeElapsed;
};