#include "input.h"
#include "game.h"

bool scan_input() {
	hidScanInput();

	u32 k_down = hidKeysDown();
	u32 k_held = hidKeysHeld();
	if (k_down & KEY_START) {
		return false;
	}

	switch(game_state) {
		case title:
			handle_title_input(k_down);
			break;
		case game:
			handle_game_input(k_held);
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
		init_game();
	}
}

void handle_game_input(u32 k_held) {
	if (k_held & KEY_DUP) {
		left_paddle.y -= left_paddle.speed;
	} else if (k_held & KEY_DDOWN) {
		left_paddle.y += left_paddle.speed;
	}
	if (left_paddle.y < 0) {left_paddle.y = 0;}
	if (left_paddle.y + left_paddle.h > TOP_SCREEN_HEIGHT) {left_paddle.y = TOP_SCREEN_HEIGHT - left_paddle.h;}

	if (k_held & KEY_X) {
		right_paddle.y -= right_paddle.speed;
	} else if (k_held & KEY_B) {
		right_paddle.y += right_paddle.speed;
	}
	if (right_paddle.y < 0) {right_paddle.y = 0;}
	if (right_paddle.y + right_paddle.h > TOP_SCREEN_HEIGHT) {right_paddle.y = TOP_SCREEN_HEIGHT - right_paddle.h;}
}

void handle_win_input(u32 k_down) {
	return;
}