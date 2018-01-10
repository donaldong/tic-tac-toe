#include <iostream>
#include <stdio.h>
#include "game.h"
using namespace std;

char P1 = 'X', P2 = 'O', EMPTY = ' ';

void display_board(string board) {
    printf("\t+---+---+---+---+\n");
    printf("\t|   | A | B | C |\n");
    printf("\t+---+---+---+---+\n");
    printf("\t| 3 | %c | %c | %c |\n", board[6], board[7], board[8]);
    printf("\t+---+---+---+---+\n");
    printf("\t| 2 | %c | %c | %c |\n", board[3], board[4], board[5]);
    printf("\t+---+---+---+---+\n");
    printf("\t| 1 | %c | %c | %c |\n", board[0], board[1], board[2]);
    printf("\t+---+---+---+---+\n");
    cout << endl;
}

void display_turn(char c) {
    printf("> %c's turn: ", c); 
}

int main() {
    TicTacToe::Game game(P1, P2, EMPTY);
    while (!game.end()) {
        display_board(game.get_board());
        display_turn(game.get_turn());
        char r, c;
        cin >> c >> r;
        while (!game.play(r - '1', tolower(c) - 'a')) {
            cout << "Invalid Move! Check Format: [A-C][1-3]" << endl;
            display_turn(game.get_turn());
            cin >> c >> r;
        }
        cout << endl;
    }
    display_board(game.get_board());
    if (game.win(P1)) printf(">>>  %c Wins The Game!!  <<<", P1);
    else if (game.win(P2))  printf(">>  %c Wins The Game!!  <<<", P2);
    else printf(">>>  Tie  <<<");
    cout << endl << endl;
    return 0;
}
