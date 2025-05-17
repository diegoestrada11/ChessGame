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
      int c = src.getCol() + d.dCol;
      int r = src.getRow() + d.dRow;
      Position dst(c, r);
      if (!dst.isValid())
         continue;

      const Piece& occ = board[dst];
      PieceType pt = occ.getType();

      if (pt == SPACE)
      {
         moves.insert(Move(src, dst, SPACE, Move::MOVE, isWhite()));
      }
      else if (occ.isWhite() != this->isWhite())
      {
         moves.insert(Move(src, dst, pt, Move::MOVE, isWhite()));
      }
   }
}