#include "Resources.h"
#include "Game.h"

unordered_map<string, SDL_Texture*> Resources::imageTable;
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(string file)
{
    auto it = imageTable.find(file);

    if (it != imageTable.end())
    {
        return it->second;
    }

    SDL_Texture* texture = IMG_LoadTexture(
        Game::GetInstance().GetRenderer(),
        file.c_str()
    );

    if (texture == nullptr)
    {
        throw runtime_error(IMG_GetError());
    }

    imageTable[file] = texture;

    return texture;
}

void Resources::ClearImages()
{
    for (auto& pair : imageTable)
    {
        SDL_DestroyTexture(pair.second);
    }

    imageTable.clear();
}

Mix_Chunk* Resources::GetSound(string file)
{
    auto it = soundTable.find(file);

    if (it != soundTable.end())
    {
        return it->second;
    }

    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

    if (chunk == nullptr)
    {
        throw runtime_error(Mix_GetError());
    }

    soundTable[file] = chunk;

    return chunk;
}

void Resources::ClearSounds()
{
    for (auto& pair : soundTable)
    {
        Mix_FreeChunk(pair.second);
    }

    soundTable.clear();
}

Mix_Music* Resources::GetMusic(string file)
{
    auto it = musicTable.find(file);

    if (it != musicTable.end())
    {
        return it->second;
    }

    Mix_Music* music = Mix_LoadMUS(file.c_str());

    if (music == nullptr)
    {
        throw runtime_error(Mix_GetError());
    }

    musicTable[file] = music;

    return music;
}

void Resources::ClearMusics()
{
    for (auto& pair : musicTable)
    {
        Mix_FreeMusic(pair.second);
    }

    musicTable.clear();
}