#include "Animator.h"
#include "GameObject.h"
#include "SpriteRenderer.h"

Animator::Animator(GameObject& associated)
    : Component(associated),
      frameStart(0), frameEnd(0), frameTime(0),
      currentFrame(0), timeElapsed(0)
{}

void Animator::Update(float dt) {
    if (frameTime == 0) return;

    timeElapsed++;

    if (timeElapsed > frameTime) {
        currentFrame++;
        timeElapsed -= frameTime;

        if (currentFrame > frameEnd) {
            currentFrame = frameStart;
        }

        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        if (sr != nullptr) {
            sr->SetFrame(currentFrame);
        }
    }
}

void Animator::Render() {}

void Animator::SetAnimation(string name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        frameStart   = it->second.frameStart;
        frameEnd     = it->second.frameEnd;
        frameTime    = it->second.frameTime;
        currentFrame = frameStart;
        timeElapsed  = 0;

        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        if (sr != nullptr) {
            sr->SetFrame(currentFrame);
        }
    }
}

void Animator::AddAnimation(string name, Animation anim) {
    auto it = animations.find(name);
    if (it == animations.end()) {
        animations.emplace(name, anim);
    }
}