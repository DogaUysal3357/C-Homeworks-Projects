#include <stdio.h>

typedef enum {play,crash,end} object_state;

void make_move( char *object1, double *position1, double *speed1, int weight1,
				char *object2, double *position2, double *speed2, int weight2,
				object_state *game_state);
double car_crash_time ( double position1, double position2, double speed1, 
						double speed2);
void print_game_state ( char object1, double position1, char object2, 
						double position2, object_state game_state);

int main()
{



	return 0;
}

/********Functions********/


 
