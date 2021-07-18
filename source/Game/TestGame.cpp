#ifndef __TESTGAME_CPP
#define __TESTGAME_CPP

#include "../Engine/Game.cpp"
#include "../Engine/GameRuntime.cpp"

namespace Game {
    class TestGame : Madeline::Runtime::Game {
        void Initialize() override {
            printf("Initializing...\n");

            
        }

        void Cleanup() override {
            printf("Cleaning up...");

            C2D_Fini();
	        C3D_Fini();
	        gfxExit();
	        romfsExit();
        }

        void Update(double deltaTime) override {
            printf("Updating...\n");
        }
        void DrawTop(double deltaTime)  override {
            printf("Drawing Top...");

            C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

            C2D_TargetClear(this->_topTarget, C2D_Color32(0xFF, 0xD8, 0xB0, 0x68));
            C2D_SceneBegin(this->_topTarget);

            C2D_DrawRectangle(50, 50, 0, 250, 250, 128, 128, 128, 128);

            C3D_FrameEnd(0);
        }
        void DrawBottom(double deltaTime) override {
            printf("Drawing Bottom...");
        }

         void OnKeyDown(int keys) override { }
         void OnKeyUp(int keys) override { }
         void OnKeyDownRepeat(int keys) override { }
         void OnKeyHeld(int keys) override { }
    };
}

#endif