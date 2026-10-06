#include <iostream>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Sound {
    public:
        Sound();
        Sound(string file);
        ~Sound();
        void Play(int times=1);
        void Stop();
        void Open(string file);
        bool IsOpen();

    private:
        Mix_Chunk* chunk;
        int channel;
};