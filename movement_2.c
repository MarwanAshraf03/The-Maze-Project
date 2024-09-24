#include "project.h"

/**
 * move_forward - Moves the player forward if no wall is in front.
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 */
void move_forward(double p_angle, double *posx, double *posy, double posdy,
				  double posdx, int side, int worldMap[mapWidth][mapHeight])
{
	if (check_wall_front(p_angle, *posx, *posy, side, worldMap))
	{
		*posy += posdy;
		*posx += posdx;
	}
}

/**
 * move_backward - Moves the player backward if no wall is behind.
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 */
void move_backward(double p_angle, double *posx, double *posy, double posdy,
				   double posdx, int side, int worldMap[mapWidth][mapHeight])
{
	if (check_wall_back(p_angle, *posx, *posy, side, worldMap))
	{
		*posy -= posdy;
		*posx -= posdx;
	}
}

/**
 * turn_right - Rotates the player right by 5 degrees.
 * @p_angle: angle showing where the player is facing
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 */
void turn_right(double *p_angle, double *posdy, double *posdx)
{
	*p_angle += 5;
	if (*p_angle >= 360)
		*p_angle -= 360;
	*posdx = cos(*p_angle * DEG) * (10 * sqrt(2));
	*posdy = sin(*p_angle * DEG) * (10 * sqrt(2));
}
/**
 * turn_left - Rotates the player left by 5 degrees.
 * @p_angle: angle showing where the player is facing
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 */
void turn_left(double *p_angle, double *posdy, double *posdx)
{
	*p_angle -= 5;
	if (*p_angle < 0)
		*p_angle += 360;
	*posdx = cos(*p_angle * DEG) * (10 * sqrt(2));
	*posdy = sin(*p_angle * DEG) * (10 * sqrt(2));
}
