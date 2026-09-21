#pragma once

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include<iostream>
using namespace std;

class Sprite
{
    public:
        Sprite();
        Sprite(string file, int frameCountW=1, int frameCountH=1);
        ~Sprite();
        void SetFrame(int frame);
        void SetFrameCount(int frameCountW, int frameCountH);
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y, int w, int h);
        int GetWidth();
        int GetHeight();
        bool IsOpen();

    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
        int frameCountW;
        int frameCountH;
};