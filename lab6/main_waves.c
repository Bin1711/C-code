#include "waves.h"
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i;
	int s = 200;
	double r = 1.00;
	double g = 1.00;
	double b = 1.00;
	double x = 0;
	double y = 0;
	for(i = 0; (argv[i]); i++) {
		if (strcmp(argv[i], "-s") == 0) {
			s = atoi(argv[i+1]);
		} else if (strcmp(argv[i], "-r") == 0) {
			r = atof(argv[i+1]);
		} else if (strcmp(argv[i], "-g") == 0) {
			g = atof(argv[i+1]);
		} else if (strcmp(argv[i], "-b") == 0) {
			b = atof(argv[i+1]);
		} else if (strcmp(argv[i], "-x") == 0) {
			x = atof(argv[i+1]);
		} else if (strcmp(argv[i], "-y") == 0) {
			y = atof(argv[i+1]);
		}
	}	
    draw_waves(s,r,g,b,x,y);
    return 0;
}
