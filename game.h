/**
 *  A Tic-Tac-Toe Game
 *
 *  @author  Donald Dong (@donaldong)
 *  @date    01/09/2018
 */

#ifndef TIC_TAC_TOE_GAME_H_
#define TIC_TAC_TOE_GAME_H_
#include <string>

namespace TicTacToe {
class Game {
public:
    /**
     *  Constructor
     *
     *  @param p1 Symbol to represent `Player 1`. Default value is 'X'.
     *  @param p2 Symbol to represent `Player 2`. Default value is 'O'.
     *  @param empty A symbol to indicate an empty space. Default value is ' '.
     */  
    Game(char p1='X', char p2='O', char empty=' ');
    
    /**
     *  Make a move as current player
     *
     *  @param row column The row and column to place the figure.
     *  @return True if the move is valid.
     */
    bool play(int row, int column);

    /**
     *  Whose turn is it?
     *
     *  @return The symbol of `Player 1` if this is `Player 1`'s turn.
     *      Or the symbol of `Player 2` otherwise.
     */
    char get_turn();

    /**
     *  Detect if a player wins the game
     *
     *  @param player The symbol representing one of the player.
     *  @return True if the player wins.
     */
    bool win(char player);

    /**
     *  Check if the game ends
     *
     *  @return True if one of the player wins or the board is full.
     */
    bool end();

    /**
     *  Get the current game board
     *
     *  @return A string representing current game board
     */
    std::string get_board();
private:
    char check();
    char __p1, __p2, __empty;
    std::string __board;
    int __steps;
    bool __end, __f1, __f2;
};
}
#endif
