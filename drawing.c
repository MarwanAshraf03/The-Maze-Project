#include "project.h"

/**
 * draw_world_on_viewport - draws the worldMap
 * @renderer2: renderer to put world on
 * @posx: x position of player
 * @posy: y position of player
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 * @worldMap: 2d representation of the game
 */
void draw_world_on_viewport(SDL_Renderer *renderer2, double posx, double posy,
							double posdy, double posdx,
							int worldMap[mapWidth][mapHeight])
{
	SDL_Rect rect;

	rect.x = (3 * screenWidth) / 4;
	rect.y = 0;
	rect.h = screenHeight / 4;
	rect.w = screenWidth / 4;
	SDL_RenderSetViewport(renderer2, &rect);
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			SDL_Rect rect1 = {
				j * BLOCK_SIZE / 4,
				i * BLOCK_SIZE / 4,
				BLOCK_SIZE / 4,
				BLOCK_SIZE / 4};

			if (worldMap[i][j] == 1)
			{
				SDL_SetRenderDrawColor(renderer2, 0, 0, 0, 255);
				SDL_RenderFillRect(renderer2, &rect1);
			}
			SDL_SetRenderDrawColor(renderer2, 128, 128, 128, 255);
			SDL_RenderDrawRect(renderer2, &rect1);
		}
	}

	SDL_RenderSetViewport(renderer2, NULL);
	draw_player_on_viewport(renderer2, rect, posx, posy, posdy, posdx);
}

/**
 * draw_player_on_viewport - draws the player
 * @renderer2: renderer to put world on
 * @rect: the map that player needs to be drawn on
 * @posx: x position of player
 * @posy: y position of player
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 */
void draw_player_on_viewport(SDL_Renderer *renderer2,
							 SDL_Rect rect, double posx, double posy, double posdy, double posdx)
{
	SDL_Rect rect1;
	float center;

	rect1.h = rect1.w = 8;
	rect1.x = rect.x + posx / 4, rect1.y = posy / 4;
	center = ((float)rect1.w / 2.0);
	SDL_SetRenderDrawColor(renderer2, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer2, &rect1);
	SDL_SetRenderDrawColor(renderer2, 0, 0, 255, 255);
	SDL_RenderDrawLine(renderer2, rect.x + posx / 4 + center, posy / 4 + center,
					   (posdx + (rect.x + posx / 4 + center)), (posdy + (posy / 4 + center)));
}
