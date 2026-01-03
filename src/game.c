#include "game.h"
#include "utils.h"

struct Paddle left_paddle;
struct Paddle right_paddle;
struct Ball ball;

static void handle_collision();

void init_game() {
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

	ball.x = TOP_SCREEN_WIDTH / 2;
	ball.y = TOP_SCREEN_HEIGHT / 2;
	ball.radius = 5.0f;
	ball.color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	ball.x_velocity = 2;
	ball.y_velocity = 1.5;
}

void update_game() {
	ball.x += ball.x_velocity;
	ball.y += ball.y_velocity;
	handle_collision();
}

static void handle_collision() {
	float left_closest_x = clamp(ball.x, left_paddle.x, left_paddle.x + left_paddle.w);
	float left_closest_y = clamp(ball.y, left_paddle.y, left_paddle.y + left_paddle.h);

	float left_dx = ball.x - left_closest_x;
	float left_dy = ball.y - left_closest_y;

	if ((left_dx * left_dx + left_dy * left_dy) <= ball.radius * ball.radius) {
		ball.x_velocity = ball.x_velocity * -1;
		ball.y_velocity = ball.y_velocity * -1;
	}

	float right_closest_x = clamp(ball.x, right_paddle.x, right_paddle.x + right_paddle.w);
	float right_closest_y = clamp(ball.y, right_paddle.y, right_paddle.y + right_paddle.h);

	float right_dx = ball.x - right_closest_x;
	float right_dy = ball.y - right_closest_y;

	if ((right_dx * right_dx + right_dy * right_dy) <= ball.radius * ball.radius) {
		ball.x_velocity = ball.x_velocity * -1;
		ball.y_velocity = ball.y_velocity * -1;
	}
}