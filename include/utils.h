#ifndef UTILS_H
#define UTILS_H

#include <3ds.h>
#include <citro2d.h>

C3D_RenderTarget* init_graphics_top();
bool scan_input();
void draw_top(C3D_RenderTarget* top);

enum state {
	title,
	game,
	p1_win,
	p2_win
};

extern enum state game_state;

#endif