#include "TileMap.h"
#include <fstream>

using namespace std;

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated){
    Load(file);
    SetTileSet(tileSet);

};

void TileMap::Load(string file){
    ifstream mapFile(file);

    if (!mapFile.is_open()) {
        throw std::runtime_error("Erro ao abrir o mapa: " + file);
    };

    mapFile >> mapWidth;
    mapFile >> mapHeight;
    mapFile >> mapDepth;

    tileMatrix.resize(mapWidth * mapHeight * mapDepth);

        for (int z = 0; z < mapDepth; z++)
    {
        for (int y = 0; y < mapHeight; y++)
        {
            for (int x = 0; x < mapWidth; x++)
            {
                mapFile >> tileMatrix[
                    x + y * mapWidth + z * mapWidth * mapHeight
                ];
            }
        }
    }

    mapFile.close();
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet.reset(tileSet);
};

void TileMap::Update(float dt)
{
}


int& TileMap::At(int x, int y, int z) {
    if (x < 0 || x >= mapWidth ||
        y < 0 || y >= mapHeight ||
        z < 0 || z >= mapDepth)
    {
        throw std::out_of_range("Posicao invalida no TileMap");
    };
    return tileMatrix[
        x + y * mapWidth + z * mapWidth * mapHeight
    ];
};

void TileMap::RenderLayer(int layer){
    for (int y = 0; y < mapHeight; y++){
        for (int x = 0; x < mapWidth; x++){
            int tile = At(x, y, layer);

            if (tile >= 0) {
                float posX = associated.box.x +
                             x * tileSet->GetTileWidth();

                float posY = associated.box.y +
                             y * tileSet->GetTileHeight();

                tileSet->RenderTile(tile, posX, posY);
            };
        }
    }
};

void TileMap::Render(){
    for (int layer = 0; layer < mapDepth; layer++)
    {
        RenderLayer(layer);
    };
};

int TileMap::GetWidth(){
    return mapWidth;
};
int TileMap::GetHeight(){
    return mapHeight;
};
int TileMap::GetDepth(){
    return mapDepth;
};