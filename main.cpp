

#include <iostream>
#include <iomanip>
#include "termcolor.hpp"
#include "Player.h"
#include "Game.h"
//#include <Windows.h>


int main()
{
    srand (time(NULL));
    
    Game myGame;
    myGame.playGame();
    //system("PAUSE");
    return 0;
}

