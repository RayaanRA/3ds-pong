#include "utils.h"

C3D_RenderTarget* init_graphics_top() {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	return C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
}