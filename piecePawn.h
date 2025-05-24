/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
*    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The PAWN class
 ************************************************************************/

#pragma once
#include "piece.h"

 /***************************************************
  * PAWN
  * The pawn
  ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Pawn() {}
   PieceType getType()            const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
private:
   void addMove(set <Move>& moves, const Position& dest, const PieceType capture, bool isEnpassant = false) const
   {
      Move m;
      m.setSource(position);
      m.setDest(dest);
      m.setCapture(capture);
      if ((fWhite && dest.getRow() == 7) || (!fWhite && dest.getRow() == 0))
         m.setPromote(QUEEN);
      if (isEnpassant)
         m.setMoveType(Move::ENPASSANT);
      moves.insert(m);
   }
};
