#include "Sound.h"
#include "Resources.h"

Sound::Sound()
    : chunk(nullptr)
{

};

Sound::Sound(string file)
    : Sound()
{
    Open(file);
};

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times -1);
};

void Sound::Stop(){
    if (chunk != nullptr){
        Mix_HaltChannel(channel);
    };
};

void Sound::Open(string file){
    chunk = Resources::GetSound(file);

    if (chunk == nullptr){
        throw std::runtime_error(Mix_GetError());
    };
};

Sound::~Sound(){
    if (chunk != nullptr){
        Stop();
    };
}