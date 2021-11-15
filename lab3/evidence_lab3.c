#include <stdlib.h>
#include <stdio.h>
#include "lab3.h"



int main(int argc, char *argv[])
{
    printf("graph of y= 0.1x^2 + 2 \n");
    graph(0.1, 0, 2, 1, -20, 20, -1, 20);
        // graph of the function y = 0.1x^2 + 2
    printf("graph of y= x^2 +2x +1 \n");
    graph(1, 2, 1, 0.5, -10, 10, 0, 20);
        // graph of the function y = x^2 + 2x + 1
    return 0;
}
