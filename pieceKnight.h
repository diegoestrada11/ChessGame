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
   }   // call base constructor properly

   ~Knight() {}

   PieceType getType() const override { return KNIGHT; }  // KNIGHT must be defined in PieceType enum
   void getMoves(std::set<Move>& moves, const Board& board) const;
   void display(ogstream* pgout) const override;
};
