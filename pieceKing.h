/***********************************************************************
 * Header File:
 *    KING
 * Author:
*    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KING
  * The king
  ***************************************************/
class King : public Piece
{
public:
   King(int c, int r, bool isWhite);
   virtual void getMoves(std::set<Move>& moves, const Board& board) const override;
   virtual void display(ogstream* pgout) const override;
   virtual PieceType getType() const override { return KING; }

private:
   struct Direction { int dCol, dRow; };
   void addKingMoves(const Direction directions[], int numDirections,
      const Board& board, std::set<Move>& moves) const;
};