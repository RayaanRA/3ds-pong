#include "utils.h"

static void draw_title();
static void draw_game();
static void draw_win();

static C2D_TextBuf title_buf;
static C2D_Text title_text;
u32 white;
u32 bg_color;

void draw_top(C3D_RenderTarget* top) {
	white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	bg_color = C2D_Color32(0x15, 0x38, 0x04, 0xFF);
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, bg_color);
	C2D_SceneBegin(top);

	switch (game_state) {
		case title:
			draw_title();
			break;
		case game:
			draw_game();
			break;
		case p1_win:
			draw_win();
			break;
		case p2_win:
			draw_win();
			break;
		default:
			break;
	}

	C3D_FrameEnd(0);
}

void init_text() {
	title_buf = C2D_TextBufNew(5);
	C2D_TextParse(&title_text, title_buf, "Pong");
	C2D_TextOptimize(&title_text);
}

static void draw_title() {
	C2D_DrawText(&title_text, C2D_AlignCenter | C2D_WithColor, TOP_SCREEN_WIDTH / 2, TOP_SCREEN_HEIGHT / 4, 0.0f, 1.0f, 1.0f, white);
}

static void draw_game() {
	return;
}

static void draw_win() {
	return;
}