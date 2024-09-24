#include "project.h"
/**
 * move_turn_player - function for player movement
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @state: a flag to end the game
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 * @map_on: a flag to show or hide the small map
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 */
void move_turn_player(double *p_angle, double *posx, double *posy,
					  double *state, double *posdy, double *posdx,
					  int *map_on, int side, int worldMap[mapWidth][mapHeight])
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			*state = 0;
			break;
		case SDL_KEYDOWN:
			switch_for_movement(ev, p_angle, posx, posy, state, posdy,
								posdx, map_on, side, worldMap);
		}
	}
}

/**
 * switch_for_movement - function for player movement
 * @ev: the event to be determined
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @state: a flag to end the game
 * @posdy: delta x position of player
 * @posdx: delta y position of player
 * @map_on: a flag to show or hide the small map
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 */
void switch_for_movement(SDL_Event ev, double *p_angle,
						 double *posx, double *posy, double *state,
						 double *posdy, double *posdx, int *map_on, int side,
						 int worldMap[mapWidth][mapHeight])
{
	int scancode = ev.key.keysym.scancode;

	switch (scancode)
	{
	case 82:
		move_forward(*p_angle, posx, posy, *posdy, *posdx, side, worldMap);
		break;
	case 81:
		move_backward(*p_angle, posx, posy, *posdy, *posdx, side, worldMap);
		break;
	case 80:
		turn_left(p_angle, posdy, posdx);
		break;
	case 79:
		turn_right(p_angle, posdy, posdx);
		break;
	case 41:
		*state = 0;
		break;
	case 16:
		*map_on ^= 1;
		break;
	default:
		handle_map_parsing(scancode, worldMap);
		break;
	}
}

/**
 * handle_map_parsing - helper function for the switch_for_movement function
 * @scancode: the button pressed
 * @worldMap: 2d representation of the game
 */
void handle_map_parsing(int scancode, int worldMap[mapWidth][mapHeight])
{
	if (scancode >= 89 && scancode <= 94)
		parse_map(scancode - 88, worldMap);
}

/**
 * check_wall_front - checks the front block if it is a wall
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 * Return: int regarding the block being a wall or not
 */
int check_wall_front(double p_angle, double posx, double posy,
					 int side, int worldMap[mapWidth][mapHeight])
{
	int checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd,
		yd, vrayx, vrayy, p2_angle = p_angle, *sh,
						  *ret = malloc(sizeof(double) * 2), *ret2 = malloc(sizeof(double) * 2);

	calculate_for_hor(&p2_angle, &rayx, &rayy,
					  &yd, &xd, &checks, &up, posx, posy);
	while (checks < 22)
		if (!iterate_for_hor(&mx, &my, &up, &checks, &rayx,
							 &rayy, &yd, &xd, worldMap))
			break;
	calculate_for_ver(&p2_angle, &vrayx, &vrayy,
					  &yd, &xd, &checks, &right, posx, posy);
	while (checks < 22)
		if (!iterate_for_ver(&mx, &my, &right, &checks, &vrayx,
							 &vrayy, &yd, &xd, worldMap))
			break;
	ret[0] = rayx;
	ret[1] = rayy;
	ret2[0] = vrayx;
	ret2[1] = vrayy;
	sh = shorter(ret, ret2, posx, posy, &side);
	float distance = dist(sh, posx, posy);

	free(sh);
	if (distance > 20)
		return (1);
	return (0);
}

/**
 * check_wall_back - checks the front block if it is a wall
 * @p_angle: angle showing where the player is facing
 * @posx: x position of player
 * @posy: y position of player
 * @side: shows wether the player is looking to upper wall or side wall
 * @worldMap: 2d representation of the game
 * Return: int regarding the block being a wall or not
 */
int check_wall_back(double p_angle, double posx, double posy,
					int side, int worldMap[mapWidth][mapHeight])
{
	int checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd,
		yd, vrayx, vrayy, p2_angle = p_angle, *sh,
						  *ret = malloc(sizeof(double) * 2), *ret2 = malloc(sizeof(double) * 2);

	if (p2_angle > 180)
		p2_angle -= 180;
	else if (p2_angle < 180)
		p2_angle += 180;
	else if (p2_angle == 180)
		p2_angle = 0;
	calculate_for_hor(&p2_angle, &rayx, &rayy,
					  &yd, &xd, &checks, &up, posx, posy);
	while (checks < 22)
		if (!iterate_for_hor(&mx, &my, &up, &checks, &rayx,
							 &rayy, &yd, &xd, worldMap))
			break;
	calculate_for_ver(&p2_angle, &vrayx, &vrayy,
					  &yd, &xd, &checks, &right, posx, posy);
	while (checks < 22)
		if (!iterate_for_ver(&mx, &my, &right, &checks, &vrayx,
							 &vrayy, &yd, &xd, worldMap))
			break;
	ret[0] = rayx;
	ret[1] = rayy;
	ret2[0] = vrayx;
	ret2[1] = vrayy;
	sh = shorter(ret, ret2, posx, posy, &side);
	float distance = dist(sh, posx, posy);

	free(sh);
	if (distance > 20)
		return (1);
	return (0);
}
