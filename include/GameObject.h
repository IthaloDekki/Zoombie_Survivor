#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Rect.h"
#include "Component.h"

class GameObject {
    public:
        GameObject();
        ~GameObject();

        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);

        template <typename T>
        T* GetComponent() {
            for (int i = 0; i < (int)components.size(); i++) {
                T* cpt = dynamic_cast<T*>(components[i]);
                if (cpt != nullptr) {
                    return cpt;
                }
            }
            return nullptr;
        }

        Rect box;

        private:
            std::vector<Component*> components;
            bool isDead;
};

#endif