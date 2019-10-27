#include <TicTacToe.h>
#include <vector>

// Default Constructor
TicTacToe::TicTacToe(){
    for(int i = 0; i < 9; i++){
        board.push_back(0);     // initializing blank board
    }
    win = 0;
    clicks = 0;
    // Notice X always starts first
    turn = true;
    message["message"] = "X's turn";
}
// Copy Constructor
TicTacToe::TicTacToe(const TicTacToe& other){
    board = other.board;
    turn = other.turn;
    message["message"] = other.message;
    win = other.win;
    clicks = other.clicks;
}
// WHen one of the squares is clicked the coordinates will be the input
ucm::json TicTacToe::clicked(int x,int y){
    ucm::json ans;
    if(win == 0){
        // checks first row 
        if(x == 0){
            // checks first column
            if(y == 0){
                // checks players turn
                if(turn){
                    // checks if the square has not been clicked 
                    if(board[0] == 0){
                        board[0] = 1;
                        turn = false;
                        ++clicks;
                    }  
                }
                else{
                    if(board[0] == 0){
                        board[0] = 2;
                        turn = true;
                        ++clicks;
                    } 
                } 
            }
            else if(y == 1){
                if(turn){
                    if(board[1] == 0){
                        board[1] = 1;
                        turn = false;
                        ++clicks;
                    }
                }
                else{
                    if(board[1] == 0){
                        board[1] = 2;
                        turn = true;
                        ++clicks;
                    } 
                }
            }
            else{
                if(turn){
                    if(board[2] == 0){
                        board[2] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[2] == 0){
                        board[2] = 2;
                        turn = true;
                        ++clicks;
                    } 
                }
            }
        }
        else if (x == 1){
            if(y == 0){
                if(turn){
                    if(board[3] == 0){
                        board[3] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[3] == 0){
                        board[3] = 2;
                        turn = true;
                        ++clicks;
                    } 
                } 
            }
            else if(y == 1){
                if(turn){
                        if(board[4] == 0){
                        board[4] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[4] == 0){
                        board[4] = 2;
                        turn = true;
                        ++clicks;
                    } 
                }
            }
            else{
                if(turn){
                    if(board[5] == 0){
                        board[5] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[5] == 0){
                        board[5] = 2;
                        turn = true;
                        ++clicks;
                    } 
                }
            }
        }
        else{
            if(y == 0){
                if(turn){
                    if(board[6] == 0){
                        board[6] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[6] == 0){
                        board[6] = 2;
                        turn = true;
                        ++clicks;
                    } 
                } 
            }
            else if(y == 1){
                if(turn){
                    if(board[7] == 0){
                        board[7] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[7] == 0){
                        board[7] = 2;
                        turn = true;
                        ++clicks;
                    } 
                }
            }
            else{
                if(turn){
                    if(board[8] == 0){
                        board[8] = 1;
                        turn = false;
                        ++clicks;
                    } 
                }
                else{
                    if(board[8] == 0){
                        board[8] = 2;
                        turn = true;
                        ++clicks;
                    } 
                }
            }
        }
    }
    ans["board"] = board;
    return ans;
}
// Fill board with all Xs
void TicTacToe::testBoard(){
    for(int i = 0; i < 9; i++){
        board[i] = 1;     // initializing X board
    }
}
// Resets the board to blank
void TicTacToe::resetBoard(){
    for(int i = 0; i < 9; i++){
        board[i] = 0;     // initializing empty board
    }
    turn = true;
    win = 0;
    clicks = 0;
}
// The board 
ucm::json TicTacToe::getBoard(){
    ucm::json ans;
    ans["board"] = board;
    return ans;
}
void TicTacToe::checkWin(){
    // checking all possible winning combos
    // Checking all row wins
    if(board[0] == 1 && board[1] == 1 && board[2] == 1){
        win = 1;
    }
    else if(board[0] == 2 && board[1] == 2 && board[2] == 2){
        win = 2;
    }
    else if(board[3] == 1 && board[4] == 1 && board[5] == 1){
        win = 1;
    }
    else if(board[3] == 2 && board[4] == 2 && board[5] == 2){
        win = 2;
    }
    else if(board[6] == 1 && board[7] == 1 && board[8] == 1){
        win = 1;
    }
    else if(board[6] == 2 && board[7] == 2 && board[8] == 2){
        win = 2;
    }
    // Checking all column wins
    if(board[0] == 1 && board[3] == 1 && board[6] == 1){
        win = 1;
    }
    else if(board[0] == 2 && board[3] == 2 && board[6] == 2){
        win = 2;
    }
    else if(board[1] == 1 && board[4] == 1 && board[7] == 1){
        win = 1;
    }
    else if(board[1] == 2 && board[4] == 2 && board[7] == 2){
        win = 2;
    }
    else if(board[2] == 1 && board[5] == 1 && board[8] == 1){
        win = 1;
    }
    else if(board[2] == 2 && board[5] == 2 && board[8] == 2){
        win = 2;
    }
    // checking all diagonal wins
    // decreasing diagonal
    if(board[0] == 1 && board[4] == 1 && board[8] == 1){
        win = 1;
    }
    else if(board[0] == 2 && board[4] == 2 && board[8] == 2){
        win = 2;
    }
    // increasing diagonal
    else if(board[6] == 1 && board[4] == 1 && board[2] == 1){
        win = 1;
    }
    else if(board[6] == 2 && board[4] == 2 && board[2] == 2){
        win = 2;
    }
    // Check if draw
    if(clicks == 9){
        win = 3;
    }
}
ucm::json TicTacToe::getMessage(){
    if(win == 0){
        if(turn){
            message["message"] = "X's turn";
        }
        else{
            message["message"] = "O's turn";
        }
    }
    else if(win == 1){
        message["message"] = "X WON!";
    }
    else if(win == 2){
        message["message"] = "0 WON!";
    }
    else{
        message["message"] = "DRAW";
    }
    return message;
}