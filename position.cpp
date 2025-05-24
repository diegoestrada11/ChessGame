/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

 /******************************************
 * POSITION SET
 * Set the internal column-row representation 
 * from separate column and row indices.
 ******************************************/
void Position::set(int c, int r)
{
   set(0xff);
   setRow(r);
   setCol(c);
}

/******************************************
* POSITION SET BOARD WIDTH HEIGHT
* Set the dimensions of a square based on the board size.
******************************************/
void Position::setBoardWidthHeight(int widthBoard, int heightBoard)
{
    if (widthBoard < 0 || heightBoard < 0)
       return;
    squareWidth = (double)widthBoard / 10.0; // 8 squares + 2 spaces
    squareHeight = (double)heightBoard / 10.0;
}

/******************************************
* POSITION ASSIGNMENT OPERATOR
* Assign a position from a chess string.
******************************************/
const Position &Position::operator =  (const char* rhs)
{
   if (rhs == NULL)
      set(0xff);
   else if(rhs[0] < 'a' || rhs[0] > 'h' || rhs[1] < '1' || rhs[1] > '8')
      set(0xff);
   else
      set(rhs[0] - 'a', rhs[1] - '1');

   return *this;
}

/******************************************
* POSITION ASSIGNMENT OPERATOR
* Copy assignment operator for Position.
******************************************/
const Position& Position::operator =  (const Position& rhs)
{
   set(rhs.colRow);
   return *this;
}

/******************************************
* POSITION INCREMENT OPERATOR
* Move the position by a delta (column and row)
* and clamp to board bounds.
******************************************/
const Position &Position::operator += (const Delta& rhs)
{
   //adjustRow(rhs.dRow);
   //adjustCol(rhs.dCol);

   int c = getCol() + rhs.dCol;
   int r = getRow() + rhs.dRow;
   if (c < 0 || c >= 8 || r < 0 || r >= 8)
      set(0xff);
   else
      set(c, r);
   return *this;
}

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   if (rhs.isValid())
      out << (char)(rhs.getCol() + 'a') << (char)(rhs.getRow() + '1');
   else
      out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates");
   }
   else
      rhs = text;
   return in;   
}

