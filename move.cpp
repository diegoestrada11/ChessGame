/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move(Position from,
   Position to,
   PieceType capture_,
   MoveType  mt_,
   bool      white_)
   : source(from)
   , dest(to)
   , promote(SPACE)
   , capture(capture_)
   , moveType(mt_)
   , isWhite(white_)
   , text()
{
}

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
bool Move::operator < (const Move& rhs) const {
   return dest.getLocation() < rhs.dest.getLocation();
}

bool Move::operator==(const Move& rhs) const {
   
   return source == rhs.source &&
      dest == rhs.dest &&
      capture == rhs.capture &&
      moveType == rhs.moveType;
   
}

void Move::read(const string& rhs) {
   string s;
   // normalize and strip connectors
   for (char c : rhs) {
      if (c == '\\' || c == '-') continue;
      s.push_back(toupper(c));
   }

   if (s == "O-O") { moveType = CASTLE_KING;   return; }
   if (s == "O-O-O") { moveType = CASTLE_QUEEN;  return; }

   if (s.size() < 4) {
      moveType = MOVE_ERROR;
      return;
   }

   // Parse squares
   source = Position(s.substr(0, 2).c_str());
   dest = Position(s.substr(2, 2).c_str());
   moveType = MOVE;

   if (s.size() >= 5) {
      promote = pieceTypeFromLetter(tolower(s[4]));
   }
}



