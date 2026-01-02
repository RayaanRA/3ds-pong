#include "game.h"
#include "utils.h"

struct Paddle left_paddle;
struct Paddle right_paddle;

void init_paddles() {
	left_paddle.x = TOP_SCREEN_WIDTH / 10;
	left_paddle.y = TOP_SCREEN_HEIGHT / 2;
	left_paddle.w = 20;
	left_paddle.h = 100;

	right_paddle.x = TOP_SCREEN_WIDTH - TOP_SCREEN_WIDTH / 10;
	right_paddle.y = TOP_SCREEN_HEIGHT / 2;
	right_paddle.w = 20;
	right_paddle.h = 100;
}