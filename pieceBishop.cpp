/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

static constexpr Delta BISHOP_DIRS[4] = 
{
  {+1,+1}, {+1,-1}, {-1,+1}, {-1,-1}
};

/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Bishop::display(ogstream* pgout) const
{
   if (!pgout)
      return;

   if (!position.isValid())
      return;

   pgout->drawBishop(position, isWhite());

}

/**********************************************
 * BISHOPS : GET MOVES
 * Generate all legal shaped moves for this bishop.
 *********************************************/
void Bishop::getMoves(std::set<Move>& moves, const Board& board) const
{
   Position src = position;

   for (auto d : BISHOP_DIRS)
   {
      for (int step = 1; step < 8; ++step)
      {
         Position dst(src.getCol() + d.dCol * step,
            src.getRow() + d.dRow * step);

         if (!dst.isValid())
            break;            

         const Piece& occ = board[dst];
         PieceType pt = occ.getType();
         bool      friendly = (occ.isWhite() == this->isWhite());

         if (pt == SPACE)
         {
            moves.insert(Move(src, dst, SPACE, Move::MOVE, isWhite()));
            continue;
         }
         else if (!friendly)
         {
            moves.insert(Move(src, dst, pt, Move::MOVE, isWhite()));
            break;
         }
         else
            break;
      }
   }
}


