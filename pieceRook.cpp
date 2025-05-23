/***********************************************************************
 * Source File:
 *    ROOK
 * Author:
 *    Ethan Leishman, Noah McSheehy, Bro. Helfrich
 * Summary:
 *    The rook class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{
   pgout->drawRook(position, !fWhite);
}


/**********************************************
 * ROOK : GET POSITIONS
 *********************************************/
void Rook::getMoves(set<Move>& moves, const Board& board) const
{
   // Horizontal and vertical directions
   const int directions[4][2] = {
      {0, 1},   // up
      {0, -1},  // down
      {1, 0},   // right
      {-1, 0}   // left
   };

   Position start = this->getPosition();

   for (int d = 0; d < 4; ++d)
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
            moves.insert(Move(start, end, SPACE, Move::MOVE, isWhite()));
         }
         else if (p.isWhite() != this->isWhite())
         {
            moves.insert(Move(start, end, p.getType(), Move::MOVE, isWhite()));
            break;
         }
         else
         {
            break;
         }
      }
   }
}

