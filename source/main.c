#include "Game/GameMain.cpp"

#include <3ds.h>
#include <stdio.h>

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
			romfsInit();
	        gfxInitDefault();
	        C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	        C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	        C2D_Prepare();
	        //consoleInit(GFX_BOTTOM, NULL);

	printf("Start...");
//---------------------------------------------------------------------------------
	GameMain(argc, argv);
}
