#include "project.h"

/**
 * main - entery point to the program
 * Return: returns state of end
 */
int main(void)
{
	int side = -1, map_on = 1;
	int worldMap[mapWidth][mapHeight];
	double posdx = 0, posdy = 0, state = 1;
	double posx = 276.365627, posy = 292.160488;
	double p_angle;
	SDL_Window *window2;
	SDL_Renderer *renderer2;

	parse_map(1, worldMap);
	posdx = 0;
	posdy = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);
	window2 = SDL_CreateWindow("The Maze Project", 0, 0,
							   screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer2 = SDL_CreateRenderer(window2, -1,
								   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	while (state)
	{
		move_turn_player(&p_angle, &posx, &posy, &state, &posdy,
						 &posdx, &map_on, side, worldMap);
		intersections_combined(renderer2, p_angle, posx, posy, side, worldMap);
		if (map_on)
			draw_world_on_viewport(renderer2, posx, posy, posdy, posdx, worldMap);
		SDL_RenderPresent(renderer2);
	}
	SDL_DestroyRenderer(renderer2);
	SDL_DestroyWindow(window2);
	SDL_Quit();
	return (0);
}
