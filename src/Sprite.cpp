#include "Sprite.h"
#include "Game.h"

Sprite::Sprite()
    :   texture(nullptr)
{};

Sprite::Sprite(string file)
    :  texture(nullptr)
{
    Open(file);
};

Sprite::~Sprite() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
};

void Sprite::Open(string file) {
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    texture = IMG_LoadTexture(
        Game::GetInstance().GetRenderer(),
        file.c_str()
    );

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

void Sprite::Render(int x, int y) {
    SDL_Rect dstrect = {
        x,
        y,
        clipRect.w,
        clipRect.h
    };

    int result = SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
    if (result != 0) {
        throw std::runtime_error(SDL_GetError());
    }
};

int Sprite::GetWidth() {
    return width;
};

int Sprite::GetHeight() {
    return height;
};


bool Sprite::IsOpen() {
    if (texture != nullptr) {
        return true;
    }else {
        return false;
    }
};

