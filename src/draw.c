#include "utils.h"

void draw_top(C3D_RenderTarget* top) {
	u32 green = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, white);
	C2D_SceneBegin(top);
	C2D_DrawCircle(200, 120, 0, 10, green, green, green, green);
	C3D_FrameEnd(0);
}