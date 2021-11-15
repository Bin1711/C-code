#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>
#include "board.h"


enum turn {
    BLACKS_TURN,
    WHITES_TURN
};

typedef enum turn turn;


enum outcome {
    IN_PROGRESS,
    BLACK_WIN,
    WHITE_WIN,
    DRAW
};

typedef enum outcome outcome;


struct game {
    unsigned int run;
    board* b;
    turn player;
};

typedef struct game game;


game* new_game(unsigned int run, unsigned int height, enum type type);

void game_free(game* g);

bool drop_piece(game* g, unsigned int col);

void earthquake(game* g, bool to_right);

outcome game_outcome(game* g);

#endif /* LOGIC_H */
