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
   // Eight possible one-step directions
   const int directions[8][2] = {
       {-1,  1}, { 0,  1}, { 1,  1},
       {-1,  0},           { 1,  0},
       {-1, -1}, { 0, -1}, { 1, -1}
   };

   Position start = this->getPosition();
   for (int d = 0; d < 8; ++d)
   {
      int dc = directions[d][0];
      int dr = directions[d][1];
      Position end(start.getCol() + dc, start.getRow() + dr);
      if (!end.isValid())
         continue;
      const Piece& p = board[end];
      if (p.getType() == SPACE || p.isWhite() != this->isWhite())
      {
         moves.insert(Move(start, end, p.getType(), Move::MOVE, this->isWhite()));
      }
   }

   // Castle
   if (nMoves == 0)
   {
      Position startPos = this->getPosition();

      // King-side castling
      if (fWhite)
      {
         const Piece& rook = board[Position("h1")];
         if (rook.getType() == ROOK && rook.isWhite() && rook.getNMoves() == 0 &&
            board[Position("f1")].getType() == SPACE &&
            board[Position("g1")].getType() == SPACE &&
            !board.isUnderAttack(Position("e1"), false) &&
            !board.isUnderAttack(Position("f1"), false) &&
            !board.isUnderAttack(Position("g1"), false))
         {
            moves.insert(Move(startPos, Position("g1"), SPACE, Move::CASTLE_KING, fWhite));
         }

         const Piece& rookQ = board[Position("a1")];
         if (rookQ.getType() == ROOK && rookQ.isWhite() && rookQ.getNMoves() == 0 &&
            board[Position("b1")].getType() == SPACE &&
            board[Position("c1")].getType() == SPACE &&
            board[Position("d1")].getType() == SPACE &&
            !board.isUnderAttack(Position("e1"), false) &&
            !board.isUnderAttack(Position("d1"), false) &&
            !board.isUnderAttack(Position("c1"), false))
         {
            moves.insert(Move(startPos, Position("c1"), SPACE, Move::CASTLE_QUEEN, fWhite));
         }
      }
      else
      {
         const Piece& rook = board[Position("h8")];
         if (rook.getType() == ROOK && !rook.isWhite() && rook.getNMoves() == 0 &&
            board[Position("f8")].getType() == SPACE &&
            board[Position("g8")].getType() == SPACE &&
            !board.isUnderAttack(Position("e8"), true) &&
            !board.isUnderAttack(Position("f8"), true) &&
            !board.isUnderAttack(Position("g8"), true))
         {
            moves.insert(Move(startPos, Position("g8"), SPACE, Move::CASTLE_KING, fWhite));
         }

         const Piece& rookQ = board[Position("a8")];
         if (rookQ.getType() == ROOK && !rookQ.isWhite() && rookQ.getNMoves() == 0 &&
            board[Position("b8")].getType() == SPACE &&
            board[Position("c8")].getType() == SPACE &&
            board[Position("d8")].getType() == SPACE &&
            !board.isUnderAttack(Position("e8"), true) &&
            !board.isUnderAttack(Position("d8"), true) &&
            !board.isUnderAttack(Position("c8"), true))
         {
            moves.insert(Move(startPos, Position("c8"), SPACE, Move::CASTLE_QUEEN, fWhite));
         }
      }
   }
}