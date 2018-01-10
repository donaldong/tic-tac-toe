#include "game.h"
#include <vector>
using namespace std;
using namespace TicTacToe;

#include <iostream>

int at(int r, int c) {
    return r * 3 + c;
}

Game::Game(char p1, char p2, char empty) {
    __p1 = p1;
    __p2 = p2;
    __empty = empty;
    __steps = 0;
    __board = string(9, empty);
    __f1 = __f2 = __end = false;
}

char Game::check() {
    vector<vector<int>> pos = {
        {0, 1, 2},  // row 1
        {3, 4, 5},  // row 2
        {6, 7, 8},  // row 3
        {0, 3, 6},  // column 1
        {1, 4, 7},  // column 2
        {2, 5, 8},  // column 3
        {0, 4, 8},  // diagonal 1
        {2, 4, 7}   // diagonal 2
    };
    for (int i = 0; i < pos.size(); ++i) {
        if (__board[pos[i][0]] == __board[pos[i][1]] && 
            __board[pos[i][1]] == __board[pos[i][2]]) 
            return __board[pos[i][0]];
    }
    return __empty;
}

bool Game::play(int row, int column) {
    if (row < 0 || row >= 3 || column < 0 || column >= 3) return false;
    int i = at(row, column);
    if (__board[i] != __empty) return false;
    __board[i] = get_turn();
    ++__steps;
    char c = check();
    if (c == __p1) __f1 = true;
    else if (c == __p2) __f2 = true;
    if (__steps == 9 || __f1 || __f2) __end = true;
    return true;
}

char Game::get_turn() {
    return __steps & 1 ? __p2 : __p1;
}

bool Game::win(char player) {
    return player == __p1 ? __f1 : __f2;
}

bool Game::end() {
    return __end;
}

string Game::get_board() {
    return __board;
}
