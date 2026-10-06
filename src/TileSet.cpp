#include "TileSet.h"
#include <iostream>

using namespace std;

TileSet::TileSet(int tileWidth, int tileHeight, string file){
    this->tileWidth=tileWidth;
    this->tileHeight=tileHeight;

    if (tileSet.IsOpen()) {
        int columns = tileSet.GetWidth() / tileWidth;
        int rows = tileSet.GetHeight() / tileHeight;
        
        tileCount = columns * rows;

        tileSet.SetFrameCount(columns, rows);
    };

};

void TileSet::RenderTile(unsigned index, float x, float y) {
    if (index < tileCount) {
        tileSet.SetFrame(index);
        tileSet.Render(x, y, tileWidth, tileHeight);
    }
};

int TileSet::GetTileWidth(){
    return  tileWidth;
};

int TileSet::GetTileHeight(){
    return tileHeight;
};