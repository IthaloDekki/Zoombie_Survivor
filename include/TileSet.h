#ifndef TILESET_H
#define TILESET_H

#include <iostream>
#include "Sprite.h"
using namespace std;

class TileSet {
    public:
        TileSet(int tileWitdth, int tileHeight, string file);
        void RenderTile(unsigned index, float x, float y);
        int GetTileWidth();
        int GetTileHeight();

    private:
        Sprite tileSet;
        int tileWidth;
        int tileHeight;
        int tileCount;
};

#endif