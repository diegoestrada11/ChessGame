/***********************************************************************
 * Header File:
 *    KNIGHT
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The KNIGHT class
 ************************************************************************/

#pragma once

#include "piece.h"

/***************************************************
* KNIGHT
* The knight, aka the "Horse"
***************************************************/
class Knight : public Piece
{
public:
   Knight(int c, int r, bool isWhite)
      : Piece(c, r, isWhite) {
   }   

   ~Knight() {}

   PieceType getType() const override { return KNIGHT; }
   void getMoves(set<Move>& moves, const Board& board) const override;
   void display(ogstream* pgout) const override;
};
