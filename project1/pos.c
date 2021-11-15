#include <stdio.h>
#include <stdlib.h>
#include "pos.h"

// represents a location on the game board
pos make_pos(unsigned int r, unsigned int c) {
    struct pos p;
    p.r = r;
    p.c = c;
    return p;
}
