#include "project.h"

/**
 * calculate_for_hor - returns the coordinates of the
 * @p2_angle: hello world
 * @rayx: hello world
 * @rayy: hello world
 * @yd: hello world
 * @xd: hello world
 * @checks: hello world
 * @up: hello world
 * @posx: x position of player
 * @posy: y position of player
 * Return: returns coordinates of the shorter point
 */
void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
					   double *yd, double *xd, int *checks, int *up, double posx, double posy)
{
	double angle_tan = -1 / tan(*p2_angle * DEG);

	*checks = 0;
	if (*p2_angle <= 360 && *p2_angle > 180)
	{
		*up = 1;
		*rayy = ((int)posy / BLOCK_SIZE) * BLOCK_SIZE;
		*rayx = (posy - *rayy) * angle_tan + posx;
		*yd = -BLOCK_SIZE;
		*xd = -(*yd) * angle_tan;
	}
	else if (*p2_angle > 0 && *p2_angle < 180)
	{
		*up = 0;
		*rayy = ((int)posy / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
		*rayx = (posy - *rayy) * angle_tan + posx;
		*yd = BLOCK_SIZE;
		*xd = -(*yd) * angle_tan;
	}
}

/**
 * iterate_for_hor - the single iteration for the horizontal line intersection
 * @mx: the x index of the map
 * @my: the y index of the map
 * @up: flag of either the player facing up or down
 * @checks: number of iterations done by the loop
 * @rayx: the x axis of the horizontal intersection
 * @rayy: the y axis of the horizontal intersection
 * @yd: the displacement for the y axis
 * @xd: the displacement for the x axis
 * @worldMap: 2d representation of the game
 * Return: the state of the intersection either 1 or 0
 */
int iterate_for_hor(int *mx, int *my, int *up, int *checks,
					double *rayx, double *rayy, double *yd,
					double *xd, int worldMap[mapWidth][mapHeight])
{
	*mx = (int)*rayx / BLOCK_SIZE;
	*my = 0;

	if (*up)
		*my = ((int)*rayy / BLOCK_SIZE) - 1;
	if (!*up)
		*my = ((int)*rayy / BLOCK_SIZE);
	*mx = abs(*mx);
	*my = abs(*my);
	if ((*mx <= mapHeight && *my <= mapWidth) && (worldMap[*my][*mx] == 0))
	{
		*rayy += *yd;
		*rayx += *xd;
		*checks += 1;
		return (1);
	}
	else
		return (0);
}

/**
 * calculate_for_ver - returns the coordinates of the
 * @p2_angle: hello world
 * @vrayx: hello world
 * @vrayy: hello world
 * @yd: hello world
 * @xd: hello world
 * @checks: hello world
 * @right: hello world
 * @posx: x position of player
 * @posy: y position of player
 * Return: returns coordinates of the shorter point
 */
void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
					   double *yd, double *xd, int *checks,
					   int *right, double posx, double posy)
{
	*checks = 0;

	double nangle_tan = -tan(*p2_angle * DEG);

	if ((*p2_angle > 270 && *p2_angle < 360) ||
		(*p2_angle >= 0 && *p2_angle < 90))
	{
		*right = 1;
		*vrayx = (int)((posx + BLOCK_SIZE) / BLOCK_SIZE) * BLOCK_SIZE;
		*vrayy = (posx - *vrayx) * nangle_tan + posy;
		*xd = BLOCK_SIZE;
		*yd = -(*xd) * nangle_tan;
	}
	else if (*p2_angle < 270 && *p2_angle > 90)
	{

		*right = 0;
		*vrayx = ((int)posx / BLOCK_SIZE) * BLOCK_SIZE;
		*vrayy = (posx - *vrayx) * nangle_tan + posy;
		*xd = -BLOCK_SIZE;
		*yd = -(*xd) * nangle_tan;
	}
}

/**
 * iterate_for_hor - the single iteration for the horizontal line intersection
 * @mx: the x index of the map
 * @my: the y index of the map
 * @right: flag of either the player facing right or left
 * @checks: number of iterations done by the loop
 * @vrayx: the x axis of the vertical intersection
 * @vrayy: the y axis of the vertical intersection
 * @yd: the displacement for the y axis
 * @xd: the displacement for the x axis
 * @worldMap: 2d representation of the game
 * Return: the state of the intersection either 1 or 0
 */
int iterate_for_ver(int *mx, int *my, int *right, int *checks,
					double *vrayx, double *vrayy, double *yd, double *xd,
					int worldMap[mapWidth][mapHeight])
{
	*my = (int)*vrayy / BLOCK_SIZE;
	if (*right)
		*mx = ((int)*vrayx / BLOCK_SIZE);
	if (!*right)
		*mx = ((int)*vrayx / BLOCK_SIZE) - 1;
	if ((*mx > mapWidth || *my > mapHeight) || (worldMap[*my][*mx] == 0))
	{
		*vrayy += *yd;
		*vrayx += *xd;
		*checks += 1;
		return (1);
	}
	else
		return (0);
}

/**
 * adjust_angle - makes the angle between 0 and 360 degrees
 * @p2_angle: the angle to be adjusted
 */
void adjust_angle(double *p2_angle)
{
	if (*p2_angle < 0)
		*p2_angle += 360;
	if (*p2_angle >= 360)
		*p2_angle -= 360;
}
