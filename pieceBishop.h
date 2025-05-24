/***********************************************************************
 * Header File:
 *    BISHOP
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The BISHOP class
 ************************************************************************/
#pragma once

class TestBishop;
#include "piece.h"

/***************************************************
* BISHOP
* The bishop
***************************************************/
class Bishop : public Piece
{
public:
   Bishop(int c, int r, bool isWhite)
      : Piece(c, r, isWhite) {
   }
   ~Bishop() {}

   PieceType getType() const override { return BISHOP; }
   void getMoves(set<Move>& moves, const Board& board) const override;
   void display(ogstream* pgout) const override;
};

