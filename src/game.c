#include "game.h"
#include "utils.h"

struct Paddle left_paddle;
struct Paddle right_paddle;

void init_paddles() {
	left_paddle.w = 8;
	left_paddle.h = 50;
	left_paddle.x = TOP_SCREEN_WIDTH / 40 - left_paddle.w / 2;
	left_paddle.y = TOP_SCREEN_HEIGHT / 2 - left_paddle.h / 2;
	left_paddle.color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

	right_paddle.w = 8;
	right_paddle.h = 50;
	right_paddle.x = (TOP_SCREEN_WIDTH - TOP_SCREEN_WIDTH / 40) - right_paddle.w / 2;
	right_paddle.y = TOP_SCREEN_HEIGHT / 2 - right_paddle.h / 2;
	right_paddle.color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
}