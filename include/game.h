#ifndef GAME_H
#define GAME_H

#include "utils.h"

struct Paddle {
	float x;
	float y;
	float w;
	float h;
	float speed;
	u32 color;
};

struct Ball {
	float x;
	float y;
	float z;
	float radius;
	u32 color;
	float x_velocity;
	float y_velocity;
	float speed;
};

extern struct Paddle left_paddle;
extern struct Paddle right_paddle;
extern struct Ball ball;

void init_game();
void update_game();

#endif