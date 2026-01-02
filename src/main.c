#include "utils.h"
#include "game.h"

enum state game_state;

int main(int argc, char* argv[]) {

	C3D_RenderTarget* top = init_graphics_top();

	while(aptMainLoop()) {
		if (!scan_input()) {
			break;
		}
		game_state = title;
		draw_top(top);
	}

	C2D_Fini();
	C3D_Fini();
	gfxExit();

	return 0;
}