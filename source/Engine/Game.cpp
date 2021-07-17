#ifndef __GAME_CPP
#define __GAME_CPP

#include <3ds.h>

namespace Madeline {
    namespace Runtime {
        class Game
        {
        private:
            /* data */
        public:
            Game(bool startToExit);
            ~Game();
            //Initliazization of the game, it is also expected that 3DS Libraries get Initialized here like for example romfsInit();
            virtual void Initialize() = 0;
            virtual void Update(double deltaTime) = 0;
            virtual void DrawTop(C3D_RenderTarget* topTarget, double deltaTime) = 0;
            virtual void DrawBottom(C3D_RenderTarget* bottomTarget, double deltaTime) = 0;

            virtual void OnKeyDown(u32 keys) {}
            virtual void OnKeyUp(u32 keys) {}
            virtual void OnKeyDownRepeat(u32 keys) {}
            virtual void OnKeyDown(u32 keys) {}
            virtual void OnKeyHeld(u32 keys) {}
        };
        
        Game::Game(bool startToExit)
        {
        }
        
        Game::~Game()
        {
        }
        
    }
}

#endif