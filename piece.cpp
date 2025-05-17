/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    Natalia Navarrete, Diego Estrada
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
 * PIECE : CONSTRUCTORS
 ***********************************************/
Piece::Piece(const Position& pos, bool isWhite)
   : position(pos), fWhite(isWhite), nMoves(0), lastMove(-1) {
}

Piece::Piece(int c, int r, bool isWhite)
   : position(c, r), fWhite(isWhite), nMoves(0), lastMove(-1) {
}

Piece::Piece(const Piece& piece)
   : position(piece.position), fWhite(piece.fWhite),
   nMoves(piece.nMoves), lastMove(piece.lastMove) {
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   if (this != &rhs)
   {
      fWhite = rhs.fWhite;    // which side
      lastMove = rhs.lastMove;  // last move number
      nMoves = rhs.nMoves;    // how many times it has moved
      position = rhs.position;  // board coordinates
   }
   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

/************************************************
 * PIECE : EQUALITY
 * Compare this piece’s type with a PieceType
 ***********************************************/
bool Piece::operator == (PieceType pt) const
{
   return getType() == pt;
}

/************************************************
 * PIECE : INEQUALITY
 * Opposite of operator==
 ***********************************************/
bool Piece::operator != (PieceType pt) const
{
   return getType() != pt;
}

void Piece::setLastMove(int currentMove) {
   lastMove = currentMove;
   nMoves++;
}

int Piece::getNMoves() const {
   return nMoves;
}

const Position& Piece::getPosition() const {
   return position;
}

bool Piece::isMoved() const {
   return nMoves > 0;
}

bool Piece::isWhite() const {
   return fWhite;
}

bool Piece::justMoved(int currentMove) const
{
   return lastMove == (currentMove - 1);
}



