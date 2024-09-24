#ifndef PROJECT_H
#define PROJECT_H
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#define mapWidth 22
#define mapHeight 22
#define screenWidth 704
#define screenHeight 704
#define BLOCK_SIZE 32
#define PI 3.14159
#define DEG 0.0174533

/* drawing.c */
void draw_world_on_viewport(SDL_Renderer *renderer2, double posx, double posy,
							double posdy, double posdx, int worldMap[mapWidth][mapHeight]);
void draw_player_on_viewport(SDL_Renderer *renderer2,
							 SDL_Rect rect, double posx, double posy, double posdy, double posdx);

/* movement_1.c */
void move_turn_player(double *p_angle, double *posx, double *posy,
					  double *state, double *posdy, double *posdx,
					  int *map_on, int side, int worldMap[mapWidth][mapHeight]);
void switch_for_movement(SDL_Event ev, double *p_angle,
						 double *posx, double *posy, double *state, double *posdy, double *posdx,
						 int *map_on, int side, int worldMap[mapWidth][mapHeight]);
void handle_map_parsing(int scancode, int worldMap[mapWidth][mapHeight]);
int check_wall_front(double p_angle, double posx, double posy,
					 int side, int worldMap[mapWidth][mapHeight]);
int check_wall_back(double p_angle, double posx, double posy,
					int side, int worldMap[mapWidth][mapHeight]);

/* movement_2.c */
void move_forward(double p_angle, double *posx, double *posy,
				  double posdy, double posdx,
				  int side, int worldMap[mapWidth][mapHeight]);
void move_backward(double p_angle, double *posx, double *posy,
				   double posdy, double posdx,
				   int side, int worldMap[mapWidth][mapHeight]);
void turn_right(double *p_angle, double *posdy, double *posdx);
void turn_left(double *p_angle, double *posdy, double *posdx);

/* maths.c */
double *shorter(double *h, double *v, double posx, double posy, int *side);
void ver_or_hor(int s, int *side);
float dist(double *shorter, double posx, double posy);

/* intersections_1.c */
void intersections_combined(SDL_Renderer *renderer2,
							double p_angle, double posx, double posy,
							int side, int worldMap[mapWidth][mapHeight]);

void draw_3d(SDL_Renderer *renderer2, double *sh,
			 int r_no, double posx, double posy, int side);
void draw_ground_ceil(SDL_Renderer *renderer2,
					  SDL_Rect rect, float line_height);

/* intersections_2.c */
void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
					   double *yd, double *xd, int *checks,
					   int *up, double posx, double posy);
int iterate_for_hor(int *mx, int *my, int *up, int *checks,
					double *rayx, double *rayy, double *yd,
					double *xd, int worldMap[mapWidth][mapHeight]);
void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
					   double *yd, double *xd, int *checks,
					   int *right, double posx, double posy);
int iterate_for_ver(int *mx, int *my, int *right, int *checks,
					double *vrayx, double *vrayy, double *yd,
					double *xd, int worldMap[mapWidth][mapHeight]);
void adjust_angle(double *p2_angle);

/* parser.c */
void parse_map(int lineNumber, int worldMap[mapWidth][mapHeight]);

#endif
