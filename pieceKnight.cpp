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
   if (!pgout)
      return;

   if (!position.isValid())
      return;

   pgout->drawKnight(position, isWhite());

}

/**********************************************
 * KNIGHT : GET MOVES
 * Generate all legal L‑shaped moves for this knight.
 *********************************************/
void Knight::getMoves(std::set<Move>& moves, const Board& board) const
{
   Position src = position;

   // All eight L‑shaped offsets
   static const Delta KNIGHT_OFFSETS[8] = {
      {+1,+2}, {+2,+1}, {+2,-1}, {+1,-2},
      {-1,-2}, {-2,-1}, {-2,+1}, {-1,+2}
   };

   for (const Delta& d : KNIGHT_OFFSETS)
   {
      Position dst(src);
      dst += d;                   // apply offset

      if (!dst.isValid())         // off‑board?
         continue;

      const Piece& occ = board[dst];
      PieceType pt = occ.getType();
      bool      friendly = (occ.isWhite() == this->isWhite());

      if (pt == SPACE)
      {
         // empty square → normal quiet move
         moves.insert(Move(src, dst, SPACE, Move::MOVE, isWhite()));
      }
      else if (!friendly)
      {
         // occupied by enemy → capture move
         moves.insert(Move(src, dst, pt, Move::MOVE, isWhite()));
      }
      // same‑color on a real Board → skip
      // (BoardEmpty returns SPACE for nullptr, so we never see SPACE here for enemy)
   }
}

