/***********************************************************************
 * Source File:
 *    ROOK
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The rook class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

static constexpr Delta ROOK_DIRS[4] = {
   { +1,  0 },  // right
   { -1,  0 },  // left
   {  0, +1 },  // up
   {  0, -1 }   // down
};

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{
   if (!pgout)
      return;

   if (!position.isValid())
      return;

   pgout->drawRook(position, !fWhite);
}

/**********************************************
 * ROOK : GET POSITIONS
 *********************************************/
void Rook::getMoves(set<Move>& moves, const Board& board) const
{
   Position src = position;

   for (auto d : ROOK_DIRS) {
      for (int step = 1; step < 8; ++step) {
         Position dst(src.getCol() + d.dCol * step,
            src.getRow() + d.dRow * step);

         if (!dst.isValid())
            break;

         const Piece& occ = board[dst];
         PieceType    pt = occ.getType();

         // empty square? slide into it
         if (pt == SPACE) {
            moves.insert(Move(src, dst, SPACE, Move::MOVE, isWhite()));
            continue;
         }

         // occupied: enemy? capture and stop
         if (occ.isWhite() != isWhite()) {
            moves.insert(Move(src, dst, pt, Move::MOVE, isWhite()));
         }

         // either way (enemy or friend) we can't go further
         break;
      }
   }
   
}

