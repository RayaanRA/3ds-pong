#include "input.h"
#include "game.h"

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

void handle_title_input(u32 k_down) {
	if (k_down & KEY_A) {
		game_state = game;
		init_paddles();
	}
}

void handle_game_input(u32 k_down) {
	return;
}

void handle_win_input(u32 k_down) {
	return;
}