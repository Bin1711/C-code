#include "board.h"
#include "logic.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    game* g = new_game(3, 4, MATRIX);
    board_show(g->b);
    printf("\n\n\n");
    bool a = drop_piece(g, 3);
    if(a) {
        printf("true\n\n");
    }
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 3);
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 3);
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 3);
    board_show(g->b);
    printf("\n\n\n");
    earthquake(g, true);
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 3);
    board_show(g->b);
    printf("\n\n\n");
    outcome o = game_outcome(g);
   if (o == IN_PROGRESS) {
        printf("IN_PROGRESS\n\n");
    } else if (o == BLACK_WIN) {
        printf("BLACK_WIN");
    } else if (o == WHITE_WIN) {
        printf("WHITE_WIN");
    } else {
        printf("DRAW");
    }
    printf("\n");
    a = drop_piece(g, 3);
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 1);
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 4);
    board_show(g->b);
    printf("\n\n\n");
    a = drop_piece(g, 3);
    board_show(g->b);
    printf("\n\n\n");
    earthquake(g, true);
    board_show(g->b);
    printf("\n\n\n");
    o = game_outcome(g);
    if (o == IN_PROGRESS) {
        printf("IN_PROGRESS\n\n");
    } else if (o == BLACK_WIN) {
        printf("BLACK_WIN");
    } else if (o == WHITE_WIN) {
        printf("WHITE_WIN");
    } else {
        printf("DRAW");
    }
    printf("\n");
    game_free(g);
    return 1;
}
