/***********************************************************************
 * Source File:
 *    KING
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

King::King(int c, int r, bool isWhite)
   : Piece(c, r, isWhite) // call base class constructor (assuming it exists)
{
   // You can add any King-specific initialization here if needed
}

/***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawKing(position, !fWhite);
}

/**********************************************
 * KING : ADD KING MOVES
 *********************************************/
void King::addKingMoves(const Direction directions[], int numDirections,
   const Board& board, std::set<Move>& moves) const
{
   Position start = this->getPosition();
   for (int i = 0; i < numDirections; ++i)
   {
      Position end(start.getCol() + directions[i].dCol,
         start.getRow() + directions[i].dRow);
      if (!end.isValid())
         continue;
      const Piece& p = board[end];
      if (p.getType() == SPACE || p.isWhite() != this->isWhite())
      {
         moves.insert(Move(start, end, p.getType(), Move::MOVE, isWhite()));
      }
   }
}

/**********************************************
 * KING : GET POSITIONS
 *********************************************/
void King::getMoves(std::set <Move>& moves, const Board& board) const
{
   // First, generate all one-step moves uniformly:
   static const Direction oneStep[8] = {
       {-1,  1}, { 0,  1}, { 1,  1},
       {-1,  0},           { 1,  0},
       {-1, -1}, { 0, -1}, { 1, -1}
   };
   addKingMoves(oneStep, 8, board, moves);

   // Now castling:
   if (nMoves != 0)
      return;     // king has already moved, no castling

   Position start = getPosition();
   if (fWhite)
   {
      // kingside
      const Piece& rookK = board[Position("h1")];
      if (rookK.getType() == ROOK && rookK.isWhite() && rookK.getNMoves() == 0
         && board[Position("f1")].getType() == SPACE
         && board[Position("g1")].getType() == SPACE
         && !board.isUnderAttack(Position("e1"), false)
         && !board.isUnderAttack(Position("f1"), false)
         && !board.isUnderAttack(Position("g1"), false))
      {
         moves.insert(Move(start, Position("g1"), SPACE, Move::CASTLE_KING, true));
      }
      // queenside
      const Piece& rookQ = board[Position("a1")];
      if (rookQ.getType() == ROOK && rookQ.isWhite() && rookQ.getNMoves() == 0
         && board[Position("b1")].getType() == SPACE
         && board[Position("c1")].getType() == SPACE
         && board[Position("d1")].getType() == SPACE
         && !board.isUnderAttack(Position("e1"), false)
         && !board.isUnderAttack(Position("d1"), false)
         && !board.isUnderAttack(Position("c1"), false))
      {
         moves.insert(Move(start, Position("c1"), SPACE, Move::CASTLE_QUEEN, true));
      }
   }
   else
   {
      // black side
      const Piece& rookK = board[Position("h8")];
      if (rookK.getType() == ROOK && !rookK.isWhite() && rookK.getNMoves() == 0
         && board[Position("f8")].getType() == SPACE
         && board[Position("g8")].getType() == SPACE
         && !board.isUnderAttack(Position("e8"), true)
         && !board.isUnderAttack(Position("f8"), true)
         && !board.isUnderAttack(Position("g8"), true))
      {
         moves.insert(Move(start, Position("g8"), SPACE, Move::CASTLE_KING, false));
      }
      const Piece& rookQ = board[Position("a8")];
      if (rookQ.getType() == ROOK && !rookQ.isWhite() && rookQ.getNMoves() == 0
         && board[Position("b8")].getType() == SPACE
         && board[Position("c8")].getType() == SPACE
         && board[Position("d8")].getType() == SPACE
         && !board.isUnderAttack(Position("e8"), true)
         && !board.isUnderAttack(Position("d8"), true)
         && !board.isUnderAttack(Position("c8"), true))
      {
         moves.insert(Move(start, Position("c8"), SPACE, Move::CASTLE_QUEEN, false));
      }
   }
}