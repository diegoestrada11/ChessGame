/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}


/**********************************************
 * PAWN : GET POSITIONS
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
   const int row = position.getRow();
   const int col = position.getCol();
   const int dir = fWhite ? +1 : -1;       // forward direction
   const int startRow = fWhite ? 1 : 6;    // starting rank for two-step
   const int promoRow = fWhite ? 7 : 0;     // back rank for promotion

   // 1) One-step forward
   Position one(col, row + dir);
   if (one.isValid() && board[one].getType() == SPACE) {
      addMove(moves, one, SPACE);
      // 2) Two-step forward
      if (row == startRow) {
         Position two(col, row + 2 * dir);
         // ensure both intermediate and destination are empty
         if (two.isValid()
            && board[two].getType() == SPACE
            && board[Position(col, row + dir)].getType() == SPACE)
            addMove(moves, two, SPACE);
      }
   }

   // 3) Normal captures
   for (int dc : {-1, +1}) {
      Position cap(col + dc, row + dir);
      if (cap.isValid()) {
         const Piece& p = board[cap];
         if (p.getType() != SPACE && p.isWhite() != fWhite)
            addMove(moves, cap, p.getType());
      }
   }

   // 4) En passant (only from rank 5 for White, rank 4 for Black)
   const int epRank = fWhite ? 4 : 3;
   if (row == epRank) {
      for (int dc : {-1, +1}) {
         Position side(col + dc, row);
         if (!side.isValid()) continue;
         const Piece& neighbor = board[side];
         if (neighbor.getType() == PAWN
            && neighbor.isWhite() != fWhite
            && neighbor.justMoved(board.getCurrentMove()))
         {
            Position land(side.getCol(), side.getRow() + dir);
            // landing square must be empty
            if (land.isValid() && board[land].getType() == SPACE)
               addMove(moves, land, PAWN, true);
         }
      }
   }
}