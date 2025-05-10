/***********************************************************************
 * Header File:
 *    MOVE 
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
   Move();


private:
   char letterFromPieceType(PieceType pt)     const {
      switch (pt)
      {
      case PAWN:   return 'p';
      case BISHOP: return 'b';
      case KNIGHT: return 'n';
      case ROOK:   return 'r';
      case QUEEN:  return 'q';
      case KING:   return 'k';
      default:     return '?'; 
      }
   }

   PieceType pieceTypeFromLetter(char letter) const {
      switch (letter)
      {
      case 'p': return PAWN;
      case 'n': return KNIGHT;
      case 'b': return BISHOP;
      case 'r': return ROOK;
      case 'q': return QUEEN;
      case 'k': return KING;
      default:  return SPACE;
      }
   }

   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


