#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include "GameObject.h"
#include "TileSet.h"
#include "Component.h"
#include <memory>
using namespace std;

class TileMap : public Component {
    public:
        TileMap(GameObject& associated, string file, TileSet* tileSet);
        void Load(string file);
        void SetTileSet(TileSet* tileSet);
        int& At(int x, int y, int z=0);
        void Render();
        void RenderLayer(int layer);
        void Update(float dt);
        int GetWidth();
        int GetHeight();
        int GetDepth();

    private:
        vector<int> tileMatrix;
        unique_ptr<TileSet> tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;
};

#endif