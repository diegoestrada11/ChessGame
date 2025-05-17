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
Move::Move()
   : source(), dest(),
   promote(SPACE), capture(SPACE),
   moveType(MOVE), isWhite(true),
   text()
{
}

Move::Move(const Position& from,
   const Position& to,
   PieceType capture,
   MoveType mt,
   bool white)
   : source(from), dest(to),
   promote(SPACE), capture(capture),
   moveType(mt), isWhite(white),
   text()
{
}

Move::Move(const std::string& notation)
   : Move()         
{
   read(notation);
   text = notation;
}

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
bool Move::operator<(const Move& rhs) const {
   if (source != rhs.source)    return source < rhs.source;
   if (dest != rhs.dest)      return dest < rhs.dest;
   if (capture != rhs.capture)   return capture < rhs.capture;
   if (moveType != rhs.moveType)  return moveType < rhs.moveType;
   return isWhite < rhs.isWhite;
}



bool Move::operator==(const Move& rhs) const {
   
   return source == rhs.source && dest == rhs.dest && capture == rhs.capture
      && promote == rhs.promote && moveType == rhs.moveType && isWhite == rhs.isWhite;
   
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



