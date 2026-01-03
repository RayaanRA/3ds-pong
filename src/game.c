#include "game.h"
#include "utils.h"

struct Paddle left_paddle;
struct Paddle right_paddle;
struct Ball ball;

static void handle_collision();
static void reset_game();

void init_game() {
	left_paddle.w = 8;
	left_paddle.h = 50;
	left_paddle.x = TOP_SCREEN_WIDTH / 40 - left_paddle.w / 2;
	left_paddle.y = TOP_SCREEN_HEIGHT / 2 - left_paddle.h / 2;
	left_paddle.speed = 5;
	left_paddle.color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

	right_paddle.w = 8;
	right_paddle.h = 50;
	right_paddle.x = (TOP_SCREEN_WIDTH - TOP_SCREEN_WIDTH / 40) - right_paddle.w / 2;
	right_paddle.y = TOP_SCREEN_HEIGHT / 2 - right_paddle.h / 2;
	right_paddle.speed = 5;
	right_paddle.color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

	ball.x = TOP_SCREEN_WIDTH / 2;
	ball.y = TOP_SCREEN_HEIGHT / 2;
	ball.radius = 5.0f;
	ball.color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	ball.x_velocity = 2;
	ball.y_velocity = 0.75;
	ball.speed = sqrt(ball.x_velocity * ball.x_velocity + ball.y_velocity * ball.y_velocity);
}

static void reset_game() {
	left_paddle.x = TOP_SCREEN_WIDTH / 40 - left_paddle.w / 2;
	left_paddle.y = TOP_SCREEN_HEIGHT / 2 - left_paddle.h / 2;
	left_paddle.speed = 5;

	right_paddle.x = (TOP_SCREEN_WIDTH - TOP_SCREEN_WIDTH / 40) - right_paddle.w / 2;
	right_paddle.y = TOP_SCREEN_HEIGHT / 2 - right_paddle.h / 2;
	right_paddle.speed = 5;

	ball.x = TOP_SCREEN_WIDTH / 2;
	ball.y = TOP_SCREEN_HEIGHT / 2;
	ball.x_velocity = 2;
	ball.y_velocity = 0.75;
	ball.speed = sqrt(ball.x_velocity * ball.x_velocity + ball.y_velocity * ball.y_velocity);	
}

void update_game() {
	ball.x += ball.x_velocity;
	ball.y += ball.y_velocity;
	handle_collision();
}

static void handle_collision() {
	float hit_point;
	float angle;
	float ball_speed_factor = 1.25f;
	float paddle_speed_factor = 1.03f;
	float left_closest_x = clamp(ball.x, left_paddle.x, left_paddle.x + left_paddle.w);
	float left_closest_y = clamp(ball.y, left_paddle.y, left_paddle.y + left_paddle.h);

	float left_dx = ball.x - left_closest_x;
	float left_dy = ball.y - left_closest_y;

	// collision with left paddle
	if ((left_dx * left_dx + left_dy * left_dy) <= ball.radius * ball.radius) {
		hit_point = (ball.y - left_paddle.y) / left_paddle.h;
		angle = (hit_point - 0.5) * MAX_BOUNCE_ANGLE;
		ball.x_velocity = cosf(angle) * ball.speed;
		ball.y_velocity = sinf(angle) * ball.speed;
		ball.x_velocity *= ball_speed_factor;
		ball.y_velocity *= ball_speed_factor;
		left_paddle.speed *= paddle_speed_factor;
		right_paddle.speed *= paddle_speed_factor;
	}

	float right_closest_x = clamp(ball.x, right_paddle.x, right_paddle.x + right_paddle.w);
	float right_closest_y = clamp(ball.y, right_paddle.y, right_paddle.y + right_paddle.h);

	float right_dx = ball.x - right_closest_x;
	float right_dy = ball.y - right_closest_y;

	// collision with right paddle
	if ((right_dx * right_dx + right_dy * right_dy) <= ball.radius * ball.radius) {
		hit_point = (ball.y - right_paddle.y) / right_paddle.h;
		angle = (hit_point - 0.5) * MAX_BOUNCE_ANGLE;
		ball.x_velocity = -cosf(angle) * ball.speed;
		ball.y_velocity = sinf(angle) * ball.speed;
		ball.x_velocity *= ball_speed_factor;
		ball.y_velocity *= ball_speed_factor;
		left_paddle.speed *= paddle_speed_factor;
		right_paddle.speed *= paddle_speed_factor;
	}

	// top/bottom, left/right screen collision
	if (ball.y - ball.radius < 0 || ball.y + ball.radius > TOP_SCREEN_HEIGHT) {
		ball.y_velocity = -ball.y_velocity;
	}

	if (ball.x - ball.radius < 0 || ball.x + ball.radius > TOP_SCREEN_WIDTH) {
		reset_game();
	}
}