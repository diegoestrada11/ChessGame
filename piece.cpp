/***********************************************************************
 * Source File:
 *    PIECE
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece& Piece::operator = (const Piece& rhs)
{
   this->fWhite = rhs.fWhite;
   this->lastMove = rhs.lastMove;
   this->nMoves = rhs.nMoves;
   this->position = rhs.position;
   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move>& movesSet, const Board& board) const
{
}

/************************************************
 * PIECE : IS WHITE
 * Returns true if this piece is white, false otherwise
 ***********************************************/
bool Piece::isWhite() const
{
   return fWhite;
}

/************************************************
 * PIECE : SET LAST MOVE
 * Sets the last move number and increments move count
 ***********************************************/
void Piece::setLastMove(int currentMove)
{
   lastMove = currentMove;
   nMoves++;
}

/************************************************
 * PIECE : JUST MOVED
 * Returns true if this piece moved in the last move
 ***********************************************/
bool Piece::justMoved(int currentMove) const
{
   return lastMove == currentMove - 1;
}
