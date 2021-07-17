#ifndef __GAMERUNTIME_CPP
#define __GAMERUNTIME_CPP

#include "Game.cpp"
#include "Helpers/TimeHelpers.cpp"

#include <citro2d.h>

namespace Madeline {
    namespace Runtime {
        class GameRuntime
        {
        private:
            Game* _game;

            C3D_RenderTarget* _top;
            C3D_RenderTarget* _bottom;
        public:
            GameRuntime(Game* game);
            ~GameRuntime();

            void RunGame();
        };
        
        GameRuntime::GameRuntime(Game* game) {
            this->_game = game;
        }
        
        GameRuntime::~GameRuntime() {
        }
        
        void GameRuntime::RunGame() {
            this->_top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
            this->_bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

            u64 deltaNow = Madeline::Helpers::GetTimeNowMilliseconds();
            u64 deltaLast = 0;

            double deltaTime = 0;

            while(aptMainLoop()){
                //Scan and report input
                hidScanInput();

                this->_game->OnKeyDown(hidKeysDown());
                this->_game->OnKeyDownRepeat(hidKeysDownRepeat());
                this->_game->OnKeyUp(hidKeysUp());
                this->_game->OnKeyHeld(hidKeysHeld());

                //Update Game
                this->_game->Update(deltaTime);

                //Draw both Screens
                this->_game->DrawTop(this->_top, deltaTime);
                this->_game->DrawBottom(this->_bottom, deltaTime);

                //Calulate Delta Time
                deltaLast = deltaNow;
                deltaNow = Madeline::Helpers::GetTimeNowMilliseconds();
                deltaTime = (double)((deltaNow - deltaLast) * 1000.0);
            }
        }
    }
}

#endif