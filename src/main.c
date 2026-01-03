#include "draw.h"
#include "input.h"
#include "update.h"

enum state game_state;

int main(int argc, char* argv[]) {
	romfsInit();
	C3D_RenderTarget* top = init_graphics_top();

	init_text();
	game_state = title;

	while(aptMainLoop()) {
		if (!scan_input()) {
			break;
		}
		update_state();
		draw_top(top);
	}

	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();
	return 0;
}