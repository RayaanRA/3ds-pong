#ifndef GAME_H
#define GAME_H

struct Paddle {
	float x,
	float y,
	float w,
	float h,
	u32 color
};

extern struct Paddle left_paddle;
extern struct Paddle right_paddle;

void init_paddles();

#endif