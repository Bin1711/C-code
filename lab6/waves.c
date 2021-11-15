#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "waves.h"

// dist: return the distance between two point
double dist(double x0, double y0, double x1, double y1) {
    double x = x1 - x0;
    double y = y1 - y0;
    return sqrt(x * x + y * y);
}

// return the color of pixel 
void draw_waves(int side_length, double r, double g, double b,
	       	int x_offset, int y_offset) {
    printf("P3\n");
    printf("%d %d\n", side_length, side_length);
    printf("255\n");
    double x = (side_length - 1)/2 + x_offset; // x of offset center
    double y = (side_length - 1)/2 + y_offset; // y of offset center
    int i; // loop for y
    int j; // loop for x
    for(i = 0; i < side_length; i++) {
        for(j = 0; j < side_length; j++) {
            double d = dist(j, i, x, y);
	    double rc = (sin(d * r) + 1) * 255/2;
	    double gc = (sin(d * g) + 1) * 255/2;
            double bc = (sin(d * b) + 1) * 255/2;
            printf("%d %d %d\n", (int) rc, (int) gc, (int) bc);
        }
    }
}

