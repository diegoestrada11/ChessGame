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
   pgout->drawKnight(position, isWhite());

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   Position src = position;

   for (const Delta& d : KNIGHT_OFFSETS)
   {
      Position dst = src;   
      dst += d;             

      if (!dst.isValid())
         continue;

      const Piece& occ = board[dst];
      PieceType pt = occ.getType();
      bool      same = (occ.isWhite() == this->isWhite());
      bool      enemy = (pt != SPACE && !same);

      if (pt == SPACE)
      {
         moves.insert(Move(src, dst, SPACE, Move::MOVE, isWhite()));
      }
      else if (enemy)
      {
         moves.insert(Move(src, dst, pt, Move::MOVE, isWhite()));
      }
      // no special “BoardEmpty” case needed any more
   }
}