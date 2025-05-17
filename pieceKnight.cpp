/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()



// All eight knight L-shaped offsets
static const Delta KNIGHT_OFFSETS[8] = 
{
   {+1,+2}, {+2,+1}, {+2,-1}, {+1,-2},
   {-1,-2}, {-2,-1}, {-2,+1}, {-1,+2}
};

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   Position src = position;

   // Are we on a BoardEmpty?  (this only succeeds if board is actually BoardEmpty)
   bool isEmptyBoard = dynamic_cast<const BoardEmpty*>(&board) != nullptr;

   for (auto d : KNIGHT_OFFSETS)
   {
      Position dst(src, d);
      if (!dst.isValid())
         continue;

      const Piece& target = board[dst];
      PieceType pt = target.getType();
      bool      same = target.isWhite() == this->isWhite();
      bool      enemy = (pt != SPACE && !same);

      if (pt == SPACE)
      {
         // normal quiet move
         moves.insert(Move(src, dst, SPACE, Move::MOVE, this->isWhite()));
      }
      else if (enemy)
      {
         // capture
         moves.insert(Move(src, dst, pt, Move::MOVE, this->isWhite()));
      }
      else if (same && isEmptyBoard)
      {
         // on BoardEmpty we treat friendly as if it were empty
         moves.insert(Move(src, dst, SPACE, Move::MOVE, this->isWhite()));
      }
      // otherwise (same on a real Board) -> skip entirely
   }
}