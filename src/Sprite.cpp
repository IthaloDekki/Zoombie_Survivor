#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

Sprite::Sprite()
    :   texture(nullptr), frameCountW(1), frameCountH(1)
{};

Sprite::Sprite(string file, int frameCountW, int frameCountH)
    :  texture(nullptr), frameCountW(frameCountW), frameCountH(frameCountH)
{
    Open(file);
};

Sprite::~Sprite() {
};

void Sprite::SetFrame(int frame){
    int frameWidth = width / frameCountW;
    int frameHeight = height / frameCountH;

    int col = frame % frameCountW;
    int row = frame / frameCountW ;
    
    int x = col * frameWidth;
    int y = row * frameHeight;

    if (x + frameWidth <= width && y + frameHeight <= height) {
        SetClip(x, y, frameWidth, frameHeight);
    }
};

void Sprite::SetFrameCount(int frameCountW, int frameCountH){
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
};

void Sprite::Open(string file) {
    texture = Resources::GetImage(file);

    if (texture == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    if (SDL_QueryTexture(
            texture,
            nullptr,
            nullptr,
            &width,
            &height) != 0)
    {
        throw std::runtime_error(SDL_GetError());
    }

    SetClip(0, 0, width, height);

};

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
};

void Sprite::Render(int x, int y, int w, int h) {
    SDL_Rect dstrect = {
        x,
        y,
        w,
        h
    };

    int result = SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
    if (result != 0) {
        throw std::runtime_error(SDL_GetError());
    }
};

int Sprite::GetWidth() {
    return width / frameCountW;
};

int Sprite::GetHeight() {
    return height / frameCountH;
};


bool Sprite::IsOpen() {
    if (texture != nullptr) {
        return true;
    }else {
        return false;
    }
};

