#include "IA.hpp"
#include <algorithm>
#include<bits/stdc++.h> 


char player = 'A', opponent = 'E'; 

bool isMovesLeft(std::vector<std::vector<char>> board)
{ 
    for (int i = 0; i<(int)board.size(); i++) 
        for (int j = 0; j<(int)board.size(); j++) 
            if (board[i][j]=='_') 
                return true; 
    return false; 
} 
  
// This is the evaluation function as discussed 
// in the previous article ( http://goo.gl/sJgv68 ) 
int evaluate(std::vector<std::vector<char>> b) 
{ 
    // Checking for Rows for X or O victory. 
    for (int row = 0; row<(int)b.size(); row++) 
    { 
        for (int i = 1 ; i < (int)b.size() -1 ; i++) {
            if (b[row][i -1]==b[row][i] && 
                b[row][i]==b[row][i+1]) 
            { 
                if (b[row][i-1]==player) 
                    return +10; 
                else if (b[row][i-1]==opponent) 
                    return -10;
            } 
            if (b[i-1][i-1]==b[i][i] && b[i][i]==b[i+1][i+1]) { 
                if (b[i-1][i-1]==player) 
                    return +10; 
                else if (b[i-1][i-1]==opponent) 
                return -10; 
            } 
            if (b[i-1][i+1]==b[i][i] && b[i][i]==b[i+1][i-1]) { 
                if (b[i-1][i+1]==player) 
                    return +10; 
                else if (b[i-1][i+1]==opponent) 
                return -10; 
            } 
        } 
    }
    return 0;  
} 
    
  
  
    // Else if none of them have won then return 0 
  
// This is the minimax function. It considers all 
// the possible ways the game can go and returns 
// the value of the board 
int minimax(std::vector<std::vector<char>> board, int depth, bool isMax) 
{ 
    int score = evaluate(board); 
  
    // If Maximizer has won the game return his/her 
    // evaluated score 
    if (score == 10) 
        return score; 
  
    // If Minimizer has won the game return his/her 
    // evaluated score 
    if (score == -10) 
        return score; 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (isMovesLeft(board)==false) 
        return 0; 
  
    // If this maximizer's move 
    if (isMax) 
    { 
        int best = -1000; 
  
        // Traverse all cells 
        for (int i = 0; i<(int)board.size(); i++) 
        { 
            for (int j = 0; j<(int)board.size(); j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]=='_') 
                { 
                    // Make the move 
                    board[i][j] = player; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    best = std::max( best, 
                        minimax(board, depth+1, !isMax) ); 
  
                    // Undo the move 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else
    { 
        int best = 1000; 
  
        // Traverse all cells 
        for (int i = 0; i<(int)board.size(); i++) 
        { 
            for (int j = 0; j<(int)board.size(); j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]=='_') 
                { 
                    // Make the move 
                    board[i][j] = opponent; 
  
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = std::min(best, 
                           minimax(board, depth+1, !isMax)); 
  
                    // Undo the move 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
} 
  
// This will return the best possible move for the player 
Move findBestMove(std::vector<std::vector<char>> board) 
{ 
    int bestVal = -1000; 
    Move bestMove; 
    bestMove.row = -1; 
    bestMove.col = -1; 
  
    // Traverse all cells, evaluate minimax function for 
    // all empty cells. And return the cell with optimal 
    // value. 
    for (int i = 0; i<(int)board.size(); i++) 
    { 
        for (int j = 0; j<(int)board.size(); j++) 
        { 
            // Check if cell is empty 
            if (board[i][j]=='_') 
            { 
                // Make the move 
                board[i][j] = player; 
  
                // compute evaluation function for this 
                // move. 
                int moveVal = minimax(board, 0, false); 
  
                // Undo the move 
                board[i][j] = '_'; 
  
                // If the value of the current move is 
                // more than the best value, then update 
                // best/ 
                if (moveVal > bestVal) 
                { 
                    bestMove.row = i; 
                    bestMove.col = j; 
                    bestVal = moveVal; 
                } 
            } 
        } 
    } 
  
    return bestMove; 
} 