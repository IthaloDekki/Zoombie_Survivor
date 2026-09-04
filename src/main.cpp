#include "Game.h"

int main (int argc, char** argv)
{
    Game::GetInstance();
    Game::GetInstance().Run();

    return 0;
};