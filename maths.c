#include "project.h"
/**
 * shorter - returns the coordinates of the
 * @h: coordinates of the horizontal intersection
 * @v: coordinates of the vertical intersection
 * @posx: x position of player
 * @posy: y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 * Return: returns coordinates of the shorter point
 */
double *shorter(double *h, double *v, double posx, double posy, int *side)
{
	float dh = sqrt(pow(h[0] - posx, 2) + pow(h[1] - posy, 2));
	float dv = sqrt(pow(v[0] - posx, 2) + pow(v[1] - posy, 2));

	if (dh < dv)
	{
		free(v);
		ver_or_hor(1, side);
		return (h);
	}
	else
	{
		free(h);
		ver_or_hor(0, side);
		return (v);
	}
}

/**
 * ver_or_hor - returns the coordinates of the
 * @s: coordinates of the horizontal intersection
 * @side: shows wether the player is looking to upper wall or side wall
 */
void ver_or_hor(int s, int *side)
{
	*side = s;
}

/**
 * dist - returns the coordinates of the
 * @shorter: coordinates of the horizontal intersection
 * @posx: x position of player
 * @posy: y position of player
 * Return: returns coordinates of the shorter point
 */
float dist(double *shorter, double posx, double posy)
{
	float dh = sqrt(pow(shorter[0] - posx, 2) + pow(shorter[1] - posy, 2));

	return (dh);
}
