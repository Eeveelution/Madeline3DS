#ifndef __GAMEMAIN_CPP
#define __GAMEMAIN_CPP

#include <3ds.h>
#include <citro2d.h>

#include "TestGame.cpp"

#include "../Engine/GameRuntime.cpp"

int GameMain(int argc, char** argv){
    Game::TestGame game;

    Madeline::Runtime::GameRuntime runtime((Madeline::Runtime::Game*)&game);

    runtime.RunGame();


	return 0;
}

#endif