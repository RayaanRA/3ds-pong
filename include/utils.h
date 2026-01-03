#ifndef UTILS_H
#define UTILS_H

#include <3ds.h>
#include <citro2d.h>
#include <unistd.h>
#include <math.h>

#define TOP_SCREEN_WIDTH 400.0f
#define TOP_SCREEN_HEIGHT 240.0f
#define PI 3.14
#define MAX_BOUNCE_ANGLE PI / 4

C3D_RenderTarget* init_graphics_top();
float clamp(float value, float min, float max);

enum state {
	title,
	game,
	p1_win,
	p2_win
};

extern enum state game_state;

#endif