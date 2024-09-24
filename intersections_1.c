#include "project.h"

/**
 * intersections_combined - finds the walls of the map
 * @renderer2: renderer to put world on
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 */
void intersections_combined(SDL_Renderer *renderer2,
							double p_angle, double posx, double posy,
							int side, int worldMap[mapWidth][mapHeight])
{
	int r_no, checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd, yd, vrayx, vrayy, p2_angle, *sh;

	p2_angle = p_angle - 30;
	adjust_angle(&p2_angle);
	for (r_no = 0; r_no < 60; r_no++)
	{
		double *ret = malloc(sizeof(double) * 2), *ret2 = malloc(sizeof(double) * 2);

		calculate_for_hor(&p2_angle, &rayx, &rayy,
						  &yd, &xd, &checks, &up, posx, posy);
		while (checks < 22)
			if (!iterate_for_hor(&mx, &my, &up, &checks, &rayx,
								 &rayy, &yd, &xd, worldMap))
				break;
		calculate_for_ver(&p2_angle, &vrayx, &vrayy,
						  &yd, &xd, &checks, &right, posx, posy);
		while (checks < 22)
			if (!iterate_for_ver(&mx, &my, &right, &checks,
								 &vrayx, &vrayy, &yd, &xd, worldMap))
				break;
		p2_angle += 1;
		adjust_angle(&p2_angle);
		ret[0] = rayx;
		ret[1] = rayy;
		ret2[0] = vrayx;
		ret2[1] = vrayy;
		sh = shorter(ret, ret2, posx, posy, &side);
		draw_3d(renderer2, sh, r_no, posx, posy, side);
		free(sh);
	}
}

/**
 * draw_3d - draws the 3d world
 * @renderer2: renderer to put world on
 * @sh: coordinates of the shorter ray either the
 * horizontal or the vertical intersection ray
 * @r_no: the ray number whcih helps in the placement of rays on the renderer
 * @posx: x position of player
 * @posy: y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 */
void draw_3d(SDL_Renderer *renderer2, double *sh,
			 int r_no, double posx, double posy, int side)
{
	float distance = dist(sh, posx, posy);
	float line_height = (BLOCK_SIZE * screenHeight) / distance;

	if (line_height > screenHeight)
		line_height = screenHeight;
	if (side)
		SDL_SetRenderDrawColor(renderer2, 229, 217, 210, 255);
	else
		SDL_SetRenderDrawColor(renderer2, 201, 183, 177, 255);
	SDL_Rect rect;

	rect.h = line_height;
	rect.w = 12;
	rect.x = ((double)r_no / 60.0) * screenWidth;
	rect.y = (screenHeight / 2) - (line_height / 2);
	SDL_RenderFillRect(renderer2, &rect);
	draw_ground_ceil(renderer2, rect, line_height);
}

/**
 * draw_ground_ceil - draw the ground and ceiling
 * @rect: the line of walls
 * @line_height: the line height of the wall
 * @renderer2: renderer to put world on
 */
void draw_ground_ceil(SDL_Renderer *renderer2,
					  SDL_Rect rect, float line_height)
{
	SDL_Rect rect1;

	rect1.y = 0;
	rect1.h = rect.y;
	rect1.x = rect.x;
	rect1.w = rect.w;
	SDL_SetRenderDrawColor(renderer2, 135, 206, 235, 255);
	SDL_RenderFillRect(renderer2, &rect1);
	rect1.y = rect.y + line_height;
	rect1.h = screenHeight - rect1.y;
	rect1.x = rect.x;
	rect1.w = rect.w;
	SDL_SetRenderDrawColor(renderer2, 103, 65, 7, 255);
	SDL_RenderFillRect(renderer2, &rect1);
}
