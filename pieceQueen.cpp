/***********************************************************************
 * Source File:
 *    QUEEN
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The queen class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Queen::display(ogstream* pgout) const
{
   if (!pgout)
      return;

   if (!position.isValid())
      return;
   pgout->drawQueen(position, !fWhite);
}


/**********************************************
* QUEEN : GET POSITIONS
*********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{
   // Directions: vertical, horizontal, and diagonal (8 total)
   const int directions[8][2] = {
       { 0,  1},  // up
       { 0, -1},  // down
       { 1,  0},  // right
       {-1,  0},  // left
       { 1,  1},  // up-right diagonal
       {-1,  1},  // up-left diagonal
       { 1, -1},  // down-right diagonal
       {-1, -1}   // down-left diagonal
   };

   Position start = this->getPosition();

   for (int d = 0; d < 8; ++d)
   {
      int dCol = directions[d][0];
      int dRow = directions[d][1];

      for (int i = 1; i < 8; ++i)
      {
         Position end(start.getCol() + dCol * i, start.getRow() + dRow * i);
         if (!end.isValid())
            break;

         const Piece& p = board[end];

         if (p.getType() == SPACE)
         {
            // Empty square — can move here
            moves.insert(Move(start, end, SPACE, Move::MOVE, isWhite()));
         }
         else if (p.isWhite() != this->isWhite())
         {
            // Opponent piece — can capture and then stop
            moves.insert(Move(start, end, p.getType(), Move::MOVE, isWhite()));
            break;
         }
         else
         {
            // Friendly piece — blocked, stop here
            break;
         }
      }
   }
}