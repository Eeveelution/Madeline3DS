#ifndef __GAME_CPP
#define __GAME_CPP

#include <3ds.h>

namespace Madeline {
    namespace Runtime {
        class Game
        {
        protected:
            C3D_RenderTarget* _topTarget;
            C3D_RenderTarget* _botTarget;
        private:
            /* data */
        public:
            Game();
            ~Game();
            //Initliazization of the game, it is also expected that 3DS Libraries get Initialized here like for example romfsInit();
            virtual void Initialize() = 0;
            virtual void Cleanup() = 0;

            virtual void Update(double deltaTime) = 0;
            virtual void DrawTop(double deltaTime) = 0;
            virtual void DrawBottom(double deltaTime) = 0;

            virtual void OnKeyDown(int keys) = 0;
            virtual void OnKeyUp(int keys) = 0;
            virtual void OnKeyDownRepeat(int keys) = 0;
            virtual void OnKeyHeld(int keys) = 0;

            void InitializeTargets(C3D_RenderTarget* topTarget, C3D_RenderTarget* botTarget) {
                this->_topTarget = topTarget;
                this->_botTarget = botTarget;
            }
        };
        
        Game::Game()
        {
        }
        
        Game::~Game()
        {
        }
        
    }
}

#endif