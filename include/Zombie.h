#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "Sound.h"

class Zombie : public Component {
    public:
        Zombie(GameObject& associated);
        void Damage(int damage);
        void Update(float dt);
        void Render();

    private:
        int hitpoints;
        Sound deathSound;
};