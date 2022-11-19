
#include "Engine/Game.h"
int main(){
    Game* game = new Game(640, 360, "TestGame");
    game->Initialize();
    delete game;
}