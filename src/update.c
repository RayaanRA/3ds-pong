#include "update.h"
#include "game.h"

static void update_title();
static void update_game();
static void update_win();

void update_state() {
	switch (game_state) {
		case title:
			update_title();
			break;
		case game:
			update_game();
			break;
		case p1_win:
		case p2_win:
			update_win();
			break;
		default:
			break;
	}
}

static void update_title() {
	return;
}

static void update_game() {

}

static void update_win() {
	return;
}