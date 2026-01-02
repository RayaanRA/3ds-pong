#ifndef UTILS_H
#define UTILS_H

#include <3ds.h>
#include <citro2d.h>

#define TOP_SCREEN_WIDTH 400.0f
#define TOP_SCREEN_HEIGHT 240.0f

C3D_RenderTarget* init_graphics_top();

enum state {
	title,
	game,
	p1_win,
	p2_win
};

extern enum state game_state;

#endif