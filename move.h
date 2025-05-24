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
#include <set>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;
class TestKnight;

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
   friend TestKnight;

   // constructor
   Move(Position from,
      Position to,
      PieceType capture = SPACE,
      MoveType  mt = MOVE,
      bool      whiteToMove = true);

   Move() : Move(INVALID, INVALID) {}
   explicit Move(string s) : Move() { read(s); text = s; }
   explicit Move(const char* s) : Move(string(s)) {}

   // compiler-generated copy, operator=, dtor are fine
   ~Move() = default;
   Move(const Move&) = default;
   Move& operator=(const Move&) = default;

   string getText()       const { return text; }
   Position getSource()   const { return source; }
   Position getDest()     const { return dest; }
   Position getProm()     const { return promote; } 
   PieceType getCapture()  const { return capture; }
   Move::MoveType getMoveType() const { return moveType; }
   bool getWhiteMove() const { return isWhite; }
   bool getEnPassant() const { return moveType == ENPASSANT; }
   bool getCastleKing() const { return moveType == CASTLE_KING; }
   bool getCastleQueen() const { return moveType == CASTLE_QUEEN; }
   bool operator < (const Move& rhs) const;
   bool operator == (const Move& rhs) const;
   bool operator == (const string& rhs) const { return getText() == rhs; }
   bool operator != (const string& rhs) const { return getText() != rhs; }
   bool operator != (const Move& rhs) const { return !(*this == rhs); }

   void read(const string& rhs);

   void update() { text = getText(); }
   void setCapture(PieceType pt) { capture = pt; update(); }
   void setWhiteMove(bool white) { isWhite = white; update(); }
   void setSource(const Position& src) { source = src; update(); }
   void setDest(const Position& des) { dest = des; update();}
   void setEnPassant() { moveType = ENPASSANT; }
   void setPromote(PieceType pt) { promote = pt; update(); }
   void setCastle(bool isKing)
   {
      moveType = isKing ? CASTLE_KING : CASTLE_QUEEN;
      update();
   }
   void setMoveType(MoveType mt) { moveType = mt; update(); }


private:
   char letterFromPieceType(PieceType pt) const 
   {
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

   PieceType pieceTypeFromLetter(char letter) const 
   {
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


