#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X){
    turn = O;
    return O;
  } else {
    turn = X;
    return X;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (row > BOARDSIZE || column > BOARDSIZE || row < 0 || column < 0){
    return Invalid;
  } else {
    board[row][column] = turn;
    return board[row][column];
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row > BOARDSIZE || column > BOARDSIZE || row < 0 || column < 0){
    return Invalid;
  } else {
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece temp = Blank;
  int k = BOARDSIZE;
  // Check Across
  temp = Blank;
  for (int i = 0; i < BOARDSIZE; i++){
    temp = board[0][i];
    for (int j = 0; j < BOARDSIZE; j++){
      if (temp != board[j][i]){
        break;
      } else {
        return board[j][i];
      }
    }
  }

  // Check Down
  temp = Blank;
  for (int i = 0; i < BOARDSIZE; i++){
    temp = board[i][0];
    for (int j = 0; j < BOARDSIZE; j++){
      if (temp != board[i][j]){
        break;
      } else {
        return board[i][j];
      }
    }
  }

  // Check Diagnal
  k = BOARDSIZE-1;
  temp = Blank;
  for (int i = 0; i < BOARDSIZE; i++){
    if (i == 0){
      temp = board[i][k];
    } else {
      temp = board[i][k];
      if (temp != board[i][k]){
        // return Invalid;
        break;
      }
    }
    k--;
    if (k = 0){
      return board[i][k];
    }
  }
  
  // No winner
  return Invalid;

  // Piece temp = Blank;

  // // Check Down
  // for(int i = 0; i < BOARDSIZE; i++){

  // }

}
