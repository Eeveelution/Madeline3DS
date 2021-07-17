#ifndef __TESTGAME_CPP
#define __TESTGAME_CPP

#include "../Engine/Game.cpp"
#include "../Engine/GameRuntime.cpp"

namespace Game {
    class TestGame : Madeline::Runtime::Game {
        void Initialize() override {
            romfsInit();
	        gfxInitDefault();
	        C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	        C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	        C2D_Prepare();
	        consoleInit(GFX_BOTTOM, NULL);
        }

        void Cleanup() override {
            C2D_Fini();
	        C3D_Fini();
	        gfxExit();
	        romfsExit();
        }

        void Update(double deltaTime) override {

        }
        void DrawTop(double deltaTime)  override {

        }
        void DrawBottom(double deltaTime) override {

        }

         void OnKeyDown(int keys) override { }
         void OnKeyUp(int keys) override { }
         void OnKeyDownRepeat(int keys) override { }
         void OnKeyHeld(int keys) override { }
    };
}

#endif