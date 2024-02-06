//
//  main.cpp
//  TicTacToe
//
//  Created by Casey Sharp on 6/7/23.
//
#include <iostream>
#include <vector>

char board[3][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
int moveRow;
int moveColumn;
char turn = 'X';
int numTurns = 0;
void showBoard(){
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << "___|___|___\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << "___|___|___\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    std::cout << "   |   |   \n";
}
void playerTurn(){
    std::cout << "Player " << turn << ", please choose a row, then a column for your turn, from 1 to 3\n";
    std::cin >> moveRow;
    std::cin >> moveColumn;
    moveRow--;
    moveColumn--;
    while((moveRow < 0 || moveRow > 2) || (moveColumn < 0 || moveColumn > 2)){
        std::cout << "From 1 to 3\n";
        std::cin >> moveRow;
        std::cin >> moveColumn;
        moveRow--;
        moveColumn--;
    }
    if(board[moveRow][moveColumn] != 'X' && board[moveRow][moveColumn] != 'O' && turn == 'X'){
        board[moveRow][moveColumn] = 'X';
        turn = 'O';
    } else if(board[moveRow][moveColumn] != 'X' && board[moveRow][moveColumn] != 'O' && turn == 'O'){
        board[moveRow][moveColumn] = 'O';
        turn = 'X';
    } else{
        std::cout << "Invalid move\n";
        playerTurn();
    }
    showBoard();
    numTurns++;
}
std::string victor(){
    for(int i = 0; i < 3; i++){
        if(((board[i][0] == board[i][1] == board[i][2]) && board[i][0] == 'X') ||
           (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == 'X')){
            return "X is victorious\n";
        } else if((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == 'O') || (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == 'O')){
            return "O is victorius\n";
        }
    }
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == 'X') || (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == 'X')){
        return "X is victorius\n";
    } else if((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == 'O') || (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == 'O')){
        return "O is victorius\n";
    } else{
        return "Draw\n";
    }
}
bool gameOver(){
    for(int i = 0; i < 3; i++){
        if((board[i][0] == board[i][1] and board[i][0] == board[i][2]) or
           (board[0][i] == board[1][i] and board[0][i] == board[2][i])){
            return false;
        }
    }
    if((board[0][0] == board[1][1] and board[0][0] == board[2][2]) or
       (board[2][0] == board[1][1] and board[2][0] == board[0][2])){
        return false;
    }
    return true;
}
int main() {
    std::cout << "Let's play Tic Tac Toe \n";
    showBoard();
    while(gameOver() and numTurns < 9){
        playerTurn();
        gameOver();
    }
    
    std::cout << victor();
}