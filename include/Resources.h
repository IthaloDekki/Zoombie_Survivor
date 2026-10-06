#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_mixer.h>
#include <unordered_map>

using namespace std;

class Resources {
    public:
        static SDL_Texture* GetImage(string file);
        static void ClearImages();
        
        static Mix_Music* GetMusic(string file);
        static void ClearMusics();

        static Mix_Chunk* GetSound(string file);
        static void ClearSounds();

    private:
        static unordered_map<string, SDL_Texture*> imageTable;
        static unordered_map<string, Mix_Music*> musicTable;
        static unordered_map<string, Mix_Chunk*> soundTable;

};

#endif