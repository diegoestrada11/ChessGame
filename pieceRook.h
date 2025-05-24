/***********************************************************************
 * Header File:
 *    ROOK
 * Author:
*    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The ROOK class
 ************************************************************************/

#pragma once
#include "piece.h"

 /***************************************************
  * ROOK
  * The rook, aka the "Tower"
  ***************************************************/
class Rook : public Piece {
public:
   Rook(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   Rook(const Position& pos, bool w) : Piece(pos, w) {}
   ~Rook() override {}

   PieceType getType() const override { return ROOK; }
   void       display(ogstream* pgout) const override;
   void       getMoves(std::set<Move>& moves, const Board& board) const override;
};