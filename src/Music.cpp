#include "Music.h"


Music::Music()
    :  music(nullptr)
{};

Music::Music(string file)
    :  music(nullptr)
{
    Open(file);
};

void Music::Play(int times) {
    if (music != nullptr) {
        Mix_PlayMusic(music, times);
    }
};

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
};

void Music::Open(string file) {
    music = Mix_LoadMUS(file.c_str());

    if (music == nullptr) {
        throw std::runtime_error(Mix_GetError());
    }
};

bool Music::IsOpen() {
    return music != nullptr;
};

Music::~Music() {
    Stop();
    
    if (music != nullptr) {
        Mix_FreeMusic(music);
    }
};