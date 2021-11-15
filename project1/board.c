#include <stdio.h>
#include <stdlib.h>
#include "board.h"

//board_new function is called to create 
//a fully-empty board of the desired size
board* board_new(unsigned int height, enum type type) {
    if (type != MATRIX) {
        fprintf(stderr, "only the matrix representation should be implemented");
        exit(1);
    }
    int i;
    int j;
    int w = 2 * height - 1;
    enum cell** u = (enum cell**)malloc(sizeof(enum cell*) * 
                                             height);
    if (u == NULL) {
        fprintf(stderr, "NULL cell");
        exit(1);
    }
    for(i = 0; i < height; i++) {
        u[i] = (enum cell*)malloc(sizeof(enum cell) * w);
        if (u[i] == NULL) {
            fprintf(stderr, "NULL row");
            exit(1);
        }
        for(j = 0; j < w; j++) {
            u[i][j] = EMPTY;
        }
    }   
    board* b = (board*)malloc(sizeof(board));
    if (b == NULL) {
        fprintf(stderr, "NULL board");
        exit(1);
    }
    b->height = height;
    b->type = type;
    b->u.matrix = u;
    return b;
}

// frees the board
void board_free(board* b) {
    if (b->type != MATRIX) {
        fprintf(stderr, "wrong type");
        exit(1);
    }
    int i;
    for (i = 0; i < b->height; i++) {
        free(b->u.matrix[i]);
    }
    free(b->u.matrix);
    free(b);
}

//prints the board to the screen, 
//along with column headers
void board_show(board* b) {
    unsigned int h = b->height;
    int w = 2 * h - 1;
    unsigned char i, j;
    enum cell** u = b->u.matrix;
    for(i = 0; i < w; i++) {
        if (i < 10) {
            printf("%u", i);
        } else if (i < 36) {
            printf("%c", i + 55);
        } else if (i < 62) {
            printf("%c", i + 61);
        } else {
            printf("?");
        }
    }
    printf("\n\n");
    for (i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            if(u[i][j] == BLACK) {
                printf("*");
            } else if (u[i][j] == WHITE) {
                printf("o");
            } else if (j < h) {
                if (i + j + 1 >= h) {
                    printf(".");
                } else {
                    printf(" ");
                }
            } else {
                if (j - i + 1 <= h) {
                    printf(".");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
        
//retrieve cells within the board
cell board_get(board* b, pos p) {
    enum cell** u = b->u.matrix;
    unsigned int h = b->height;
    unsigned int r = p.r;
    unsigned int col = p.c;
    if ((r > h - 1) || (r < 0)) {
        fprintf(stderr, "invalid pos");
        exit(1);
    }
    if ((col < h) && (col + r + 1< h)) {
        fprintf(stderr, "invalid pos");
        exit(1);
    }
    if ((col >= h) && (col - r >= h)) {
        fprintf(stderr, "invalid pos");
        exit(1);
    }
    return u[r][col];
}

// modify cells within the board
void board_set(board* b, pos p, cell c) {
    enum cell** u = b->u.matrix;
    unsigned int h = b->height;
    unsigned int r = p.r;
    unsigned int col = p.c;
    if ((r > h - 1) || (r < 0)) {
        fprintf(stderr, "invalid pos");
        exit(1);
    }
    if ((col + 1 <= h) && (col + r + 1 < h)) {
        fprintf(stderr, "invalid pos");
        exit(1);
    }
    if ((col >= h) && (col - r + 1 > h)) {
        fprintf(stderr, "invalid pos");
        exit(1);
    }
    u[r][col] = c;
}
