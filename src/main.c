#include <3ds.h>
#include <citro2d.h>

int main(int argc, char* argv[]) {

	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	u32 green = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

	while(aptMainLoop()) {
		hidScanInput();

		u32 k_down = hidKeysDown();
		if (k_down & KEY_START) {
			break;
		}

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, white);
		C2D_SceneBegin(top);

		C2D_DrawCircle(200, 120, 0, 10, green, green, green, green);

		C3D_FrameEnd(0);

	}

	C2D_Fini();
	C3D_Fini();
	gfxExit();

	return 0;
}