#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <stdbool.h>

//create a new game with the specified size 
//and run length and using the desired data representation 
game* new_game(unsigned int run, unsigned int height, 
                                    enum type type) {
    board* b = board_new(height, type);
    int w = 2 * height - 1;
    if ((run > w) || (run < 1)) {
        fprintf(stderr, "the game is impractical");
        exit(1);
    }
    game* g = (game*)malloc(sizeof(game));
    if (g == NULL) {
        fprintf(stderr, "NULL gane");
        exit(1);
    }
    g->run = run;
    g->b = b;
    g->player = BLACKS_TURN;
    return g;
}

// free the game
void game_free(game* g) {
    board_free(g->b);
    free(g);
}

//places a piece belonging to the 
//player whose turn it is
//in the specified column
//If the column is already full, it does nothing and 
//returns false; otherwise, it returns true
//also the responsibility of this function to 
//change the turn to the next player
bool drop_piece(game* g, unsigned int col) {
    unsigned int h = g->b->height;
    int i = h - 1;
    turn p = g->player;
    board* b = g->b;
    if (col < h) {  
        while ((i + col + 1>= h) && 
                    (board_get(b, make_pos(i, col)) != EMPTY)) {
            i--;
        }
        if (i + col + 1>= h) {
            if (p == BLACKS_TURN) {
                board_set(b, make_pos(i, col), BLACK);
                g->player = WHITES_TURN;
                return true;
            } else {
                board_set(b, make_pos(i, col), WHITE);
                g->player = BLACKS_TURN;
                return true;
            }
        } else {
            return false;
        }
    } else {
        while ((col - i < h) &&
                    (board_get(b, make_pos(i, col)) != EMPTY)) {
            i--;
        }
        if (col - i <= h - 1) {
            if (p == BLACKS_TURN) {
                board_set(b, make_pos(i, col), BLACK);
                g->player = WHITES_TURN;
                return true;
            } else {
                board_set(b, make_pos(i, col), WHITE);
                g->player = BLACKS_TURN;
                return true;
            }
        } else {
            return false;
        }
    }
}

//performs an earthquake 
//sliding everything as far in the specified direction
//within its row, as possible, and then, 
//allowing any effects of gravity to occur
void earthquake(game* g, bool to_right) {
    unsigned int h = g->b->height;
    board* b = g->b;
    int i, j, k;
    if (to_right) {
        for(i = 0; i < h; i++) {
            for (j = h + i - 1; j + i + 1 >= h; j--) {
                pos p1 = make_pos(i, j); 
                if (board_get(b, p1) == EMPTY) {  
                    for(k = j - 1; (k + i + 1>= h) 
                        && (board_get(b, make_pos(i, k)) == EMPTY); k--);
                    if (k + i + 1>= h) {
                        pos pk = make_pos(i, k); 
                        board_set(b, p1, board_get(b, pk)); 
                        board_set(b, pk, EMPTY); 
                    } 
                }
            }
        }    
    } else {
        for(i = 0; i < h; i++) {
            for (j = h - i - 1; j - i + 1<= h; j++) {
                pos p1 = make_pos(i, j);
                if (board_get(b, p1) == EMPTY) {
                    for(k = j + 1; (k - i + 1<= h)
                        && (board_get(b, make_pos(i, k)) == EMPTY); k++);
                    if (k - i + 1<= h) {
                        pos pk = make_pos(i, k);
                        board_set(b, p1, board_get(b, pk));
                        board_set(b, pk, EMPTY);
                    }
                }
            }
        }
    }
    for (j = 1; j < h; j++) {
        for (k = h - 2; k + j + 1 >= h; k--) {
            for (i = h - 2; i + j + 1>= h; i--) {
                pos p1 = make_pos(i, j);
                pos p2 = make_pos(i + 1, j);
                cell c1 = board_get(b, p1);
                cell c2 = board_get(b, p2);
                if ((c1 != EMPTY) && (c2 == EMPTY)) {
                    board_set(b, p2, c1);
                    board_set(b, p1, EMPTY);
                }
            }
        }
    }
    for (j = h; (2 * h - 2) > j; j++) {
        for (k = h - 2; j - k < h; k--) {
            for (i = h - 2; j - i < h; i--) {
                pos p1 = make_pos(i, j);
                int i1 = i + 1;
                pos p2 = make_pos(i1, j);
                cell c1 = board_get(b, p1);
                cell c2 = board_get(b, p2);
                if ((c1 != EMPTY) && (c2 == EMPTY)) {
                    board_set(b, p2, c1);
                    board_set(b, p1, EMPTY); 
                }
            }
        }   
    } 
    if (g->player == BLACKS_TURN) {
        g->player = WHITES_TURN;
    } else {
        g->player = BLACKS_TURN;
    }
}

//report the outcome of a completed game
//or that the game is still in progress.
outcome game_outcome(game* g) {
    int i; // for row
    int j; // for column
    int k; // for column
    int bl; 
    int wh;
    unsigned int h = g->b->height;
    board* b = g->b;
    cell c, c1;
    unsigned int r = g->run;
    int black = 0;
    int white = 0;
    int e = 0;
    // search for row
    for (i = 0; (i < h) && ((black == 0) 
                        || (white == 0)); i++) {
        for (j = h - 1 - i; j - i + 1 <= h; j++) {
            if (bl == r) {
                black++;
            } else if (wh == r) {
                white++;
            }
            c = board_get(b, make_pos(i, j)); 
            if (j == h - 1 - i) {
                if (c == BLACK) {
                    bl = 1;
                    wh = 0;
                } else if (c == WHITE) {
                    bl = 0;
                    wh = 1;
                } else {
                    e++;
                    bl = 0;
                    wh = 0;
                }
            } else {
                c1 = board_get(b, make_pos(i, j - 1));
                if ((c == BLACK) && (c1 == BLACK)) {
                    bl++;
                } else if ((c == WHITE) && (c1 == WHITE)) {
                    wh++;
                } else if (c == BLACK) {
                    bl = 1;
                    wh = 0;
                } else if (c == WHITE){
                    bl = 0;
                    wh = 1;
                } else {
                    bl = 0;
                    wh = 0;
                    e++;
                }
            }
        }
        bl = 0;
        wh = 0;
    }
    if ((black > 0) && (white > 0)) {
        return DRAW;
    }
    //search for column with j from 0 to h - 1
    for (j = 0; (j < h) && ((black == 0) 
                            || (white == 0)) ; j++) {
        for (i = h - 1; (i + j + 1>= h)
                && (board_get(b, make_pos(i, j)) != EMPTY); i--) {
            if (bl == r) {
                black++;
            } else if (wh == r) {
                white++;
            }
            c = board_get(b, make_pos(i, j));
            if (i == h - 1) {
                if (c == BLACK) {
                    bl = 1;
                    wh = 0;
                } else {
                    bl = 0;
                    wh = 1;
                }
            } else {
                c1 = board_get(b, make_pos(i + 1, j));
                if ((c == BLACK) & (c1 == BLACK)) {
                    bl++;
                } else if ((c == WHITE) && (c1 == WHITE)) {
                    wh++;
                } else if (c == BLACK) {
                    bl = 1;
                    wh = 0;
                } else {
                    bl = 0;
                    wh = 1;
                }
            }
        }
        if (i + j + 1>= h) {
            e++;
        }
        bl = 0;
        wh = 0;
    }
    if ((black > 0) && (white > 0)) {
        return DRAW;
    }
    // search for column but with j from h to 2*h -2
    for (j = h; (2 * h - 1 > j) && ((black == 0)
                            || (white == 0)) ; j++) {
        for (i = h - 1; (j - i < h)
                && (board_get(b, make_pos(i, j)) != EMPTY); i--) {
            if (bl == r) {
                black++;
            } else if (wh == r) {
                white++;
            }
            c = board_get(b, make_pos(i, j));
            if (i == h - 1) {
                if (c == BLACK) {
                    bl = 1;
                    wh = 0;
                } else {
                    bl = 0;
                    wh = 1;
                }
            } else {
                c1 = board_get(b, make_pos(i + 1, j));
                if ((c == BLACK) & (c1 == BLACK)) {
                    bl++;
                } else if ((c == WHITE) && (c1 == WHITE)) {
                    wh++;
                } else if (c == BLACK) {
                    bl = 1;
                    wh = 0;
                } else {
                    bl = 0;
                    wh = 1;
                }
            }
        }
        if (j - i + 1 <= h) {
            e++;
        }
        bl = 0;
        wh = 0;
    }
    if ((black > 0) && (white > 0)) {
        return DRAW;
    }
    // search for diagonal 
    if (r <= h) {
        // right to left (from bottom to top)
        for (j = 2 * r - 2; (2 * h - 1 > j) && ((black == 0) 
                            || (white == 0)); j++) {
            k = j; 
            for (i = h - 1; i + k + 1 >= h; i--) {
                if (bl == r) {
                    black++;
                } else if (wh == r) {
                    wh++;
                }
                c = board_get(b, make_pos(i, k));
                if (i + 1 == h) {
                    if (c == BLACK) {
                        bl = 1;
                        wh = 0;
                    } else if (c == WHITE){
                        bl = 0;
                        wh = 1;
                    } else {
                        bl = 0;
                        wh = 0;
                    }
                } else {
                    c1 = board_get(b, make_pos(i + 1, k + 1));
                    if ((c == BLACK) && (c1 == BLACK)) {
                        bl++;
                    } else if ((c == WHITE) && (c1 == WHITE)) {
                        wh++;
                    } else if (c == BLACK) {
                        bl = 1;
                        wh = 0;
                    } else if (c == WHITE){
                        bl = 0;
                        wh = 1;
                    } else {
                        bl = 0;
                        wh = 0;
                    }
                }
                k--;
            }
            bl = 0;
            wh = 0;
        }
        if ((black > 0) && (white > 0)) {
            return DRAW;
        }
        // left to right ( bottom to top)
        for (j = 0; (2 * h - 2 * r > j) && ((black == 0)
                            || (white == 0)); j++) {
            k = j;
            for (i = h - 1; k - i < h; i--) {
                if (bl == r) {
                    black++;
                } else if (wh == r) {
                    wh++;
                }
                c = board_get(b, make_pos(i, k));
                if (i + 1== h) {
                    if (c == BLACK) {
                        bl = 1;
                        wh = 0;
                    } else if (c == WHITE){
                        bl = 0;
                        wh = 1;
                    } else {
                        bl = 0;
                        wh = 0;
                    } 
                } else {
                    c1 = board_get(b, make_pos(i + 1, k - 1));
                    if ((c == BLACK) && (c1 == BLACK)) {
                        bl++;
                    } else if ((c == WHITE) && (c1 == WHITE)) {
                        wh++;
                    } else if (c == BLACK) {
                        bl = 1;
                        wh = 0;
                    } else if (c == WHITE){
                        bl = 0;
                        wh = 1;
                    } else {
                        bl = 0;
                        wh = 0;
                    }
                }
                k++;
            }
            bl = 0;
            wh = 0;
        }
        if ((black > 0) && (white > 0)) {
            return DRAW;
        }
    }
    if ((black > 0) && (white == 0)) {
        return BLACK_WIN;
    } else if ((black == 0) && (white > 0)) {
        return WHITE_WIN;
    } else if (e == 0) {
        return DRAW;
    } else {
        return IN_PROGRESS;
    }
} 
