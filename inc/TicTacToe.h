#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <server.h>

/* 
This object serves as the backend to the Tic Tac Toe Game

The game board is going to be implemented thru the use of magic numbers
board:
0 = umarked
1 = X
2 = O

win will keep track of who's winning
win:
0 = no one has won
1 = X Won!
2 = O Won!
3 = Draw

Message:
Game's state message for display

turn:
true = X's turn
false = O's turn 

clicks keeps track of the number of clicks
*/

class TicTacToe{
    // using magic numbers
    std::vector<int> board;
    ucm::json message;
    int win;
    bool turn;
    int clicks;

public:
    // Default Constructor
    TicTacToe();
    // Copy Constructor
    TicTacToe(const TicTacToe&);
    
    ucm::json getBoard();
    void testBoard();
    void resetBoard();

    ucm::json clicked(int,int);

    void checkWin();

    ucm::json getMessage();

    // Deconstructor
    // ~TicTacToe();
};

#endif