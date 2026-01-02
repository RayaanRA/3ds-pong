#include "game.h"
#include "utils.h"

static void handle_title_input(u32 k_down);
static void handle_game_input(u32 k_down);
static void handle_win_input(u32 k_down);

bool scan_input() {
	hidScanInput();

	u32 k_down = hidKeysDown();
	if (k_down & KEY_START) {
		return false;
	}

	switch(game_state) {
		case title:
			handle_title_input(k_down);
			break;
		case game:
			handle_game_input(k_down);
			break;
		case p1_win:
			handle_win_input(k_down);
			break;
		case p2_win:
			handle_win_input(k_down);
			break;
		default:
			break;
	}

	return true;

}

static void handle_title_input(u32 k_down) {
	if (k_down & KEY_A) {
		game_state = game;
	}
}

static void handle_game_input(u32 k_down) {
	return;
}

static void handle_win_input(u32 k_down) {
	return;
}