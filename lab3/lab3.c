#include "lab3.h"
void graph(double a, double b, double c, double step,
             int xleft, int xright, int ybottom, int ytop) {
    int i = ytop;
    for (;i >= ybottom; i--) { 
        int j = xleft;
        for (; j <= xright; j++) {
            double x = j * step;
            double y = a * x * x + b * x + c;
            double z = y/step - i;
            if ((z < 1) && (z >= 0)) {
                printf("*");
            } else if ((j == 0) && (i == 0)) {
                printf("+");
            } else if (j == 0) {
                printf("|");
            } else if (i == 0) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
} 
                    
