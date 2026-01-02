#include "utils.h"

static void draw_title();
static void draw_game();
static void draw_win();

static C2D_TextBuf title_buf;
static C2D_Text title_text;
static C2D_TextBuf title_play_buf;
static C2D_Text title_play_text;
static C2D_Font font_pixelify;
static C2D_TextBuf title_exit_buf;
static C2D_Text title_exit_text;

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
	font_pixelify = C2D_FontLoad("romfs:/resources/PixelifySans.bcfnt");
	title_buf = C2D_TextBufNew(8);
	C2D_TextFontParse(&title_text, font_pixelify, title_buf, "Pong");
	C2D_TextOptimize(&title_text);

	title_play_buf = C2D_TextBufNew(32);
	C2D_TextFontParse(&title_play_text, font_pixelify, title_play_buf, "Press A to play");
	C2D_TextOptimize(&title_play_text);

	title_exit_buf = C2D_TextBufNew(64);
	C2D_TextFontParse(&title_exit_text, font_pixelify, title_exit_buf, "Press START at any time to exit");
	C2D_TextOptimize(&title_exit_text);
}

static void draw_title() {
	C2D_DrawText(&title_text, 
		C2D_AlignCenter | C2D_WithColor, TOP_SCREEN_WIDTH / 2, TOP_SCREEN_HEIGHT / 4, 0.0f, 1.0f, 1.0f, white);

	C2D_DrawText(&title_play_text, 
		C2D_AlignCenter | C2D_WithColor, TOP_SCREEN_WIDTH / 2, TOP_SCREEN_HEIGHT / 2, 0.0f, 0.75f, 0.75f, white);

	C2D_DrawText(&title_exit_text, 
		C2D_AlignCenter | C2D_WithColor, TOP_SCREEN_WIDTH / 2, TOP_SCREEN_HEIGHT / 1.2f, 0.0f, 0.45f, 0.45f, white);
}

static void draw_game() {
	return;
}

static void draw_win() {
	return;
}