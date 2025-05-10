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
 * POSITION ISVALID
 * Check if the internal column-row is a
 * valid board coordinate.
 ******************************************/
bool Position::isValid()   const
{
   unsigned col = (colRow >> 4) & 0x0F;
   unsigned row = colRow & 0x0F;
   return (col < 8 && row < 8);
}

 /******************************************
 * POSITION SET
 * Set the internal column-row representation 
 * from separate column and row indices.
 ******************************************/
void Position::set(int c, int r)
{
   uint8_t colRowNew;

   if (c < 0 || c >= 8)
      colRowNew = 0xFF;
   else if (r < 0 || r >= 8)
      colRowNew = uint8_t((c << 4) | 0x0F);
   else
      colRowNew = uint8_t(((c & 0x0F) << 4) | (r & 0x0F));

   set(colRowNew);
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
   if (!rhs || strlen(rhs) != 2)
   {
      set(-1, -1);
      return *this;
   }

   char cChar = tolower(rhs[0]);
   char rChar = rhs[1];
   int c = ('a' <= cChar && cChar <= 'h') ? cChar - 'a' : -1;
   int r = ('1' <= rChar && rChar <= '8') ? rChar - '1' : -1;

   set(c, r);
   return *this;
}

/******************************************
* POSITION ASSIGNMENT OPERATOR
* Copy assignment operator for Position.
******************************************/
const Position& Position::operator =  (const Position& rhs)
{
   if (this != &rhs)
      this->colRow = rhs.colRow;
   return *this;
}

/******************************************
* POSITION INCREMENT OPERATOR
* Move the position by a delta (column and row)
* and clamp to board bounds.
******************************************/
const Position &Position::operator += (const Delta& rhs)
{
   int c = getCol() + rhs.dCol;
   int r = getRow() + rhs.dRow;

   if (c < 0 || c >= 8 || r < 0 || r >= 8)
      set(-1, -1);
   else
      set(c, r);

   return *this;
}

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   return in;   
}

