/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE = 32;   // number of pixels in a square by default

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0 };
const Delta ADD_C = { 0,  1 };
const Delta SUB_R = { -1,  0 };
const Delta SUB_C = { 0, -1 };


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs) { colRow = 0x00; }
   Position() : colRow(0x99) {}
   bool isInvalid() const { return !isValid(); }
   bool isValid()   const
   {
      unsigned col = (colRow >> 4) & 0x0F;
      unsigned row = colRow & 0x0F;
      return (col < 8 && row < 8);
   }
   void setValid() {}
   void setInvalid() {}
   bool operator <  (const Position& rhs) const { return this->colRow < rhs.colRow; }
   bool operator == (const Position& rhs) const { return this->colRow == rhs.colRow; }
   bool operator != (const Position& rhs) const { return this != &rhs; }
   const Position& operator =  (const Position& rhs)
   {
      if (this != &rhs)
         this->colRow = rhs.colRow;
      return *this;
   }

   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(0x99) {}
   int getLocation() const { return getRow() * 8 + getCol(); }
   void setLocation(int location) {}


   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow(0x99) { set(c, r); }
   virtual int getCol() const { return isInvalid() ? -1 : (colRow >> 4) & 0x0F;}
   virtual int getRow() const { return isInvalid() ? -1 : colRow & 0x0F; }
   void setRow(int r)         { colRow = (colRow & 0xF0) | (r & 0x0F); }
   void setCol(int c)         { colRow = (colRow & 0x0F) | ((c & 0x0F) << 4); }
   void set(int c, int r)
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

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x99) {}
   const Position& operator =  (const char* rhs) 
   {
      if (!rhs || strlen(rhs) != 2)
      {
         set(-1, -1);
         return *this;
      }

      char cChar = tolower(rhs[0]);
      char rChar = rhs[1];
      int c = ('a'<= cChar && cChar <= 'h') ? cChar - 'a' : -1;
      int r = ('1'<= rChar && rChar <= '8') ? rChar - '1' : -1;

      set(c, r);
      return *this;
   }
   const Position& operator =  (const string& rhs) 
   {
      return operator=(rhs.c_str());
   }

   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const
   {
      return (int)((double)getCol() * getSquareWidth() + getSquareWidth());
   }
   int getY()   const
   {
      return (int)((double)getRow() * getSquareHeight() + getSquareHeight());
   }
   void setXY(double x, double y)
   {
      int c = (int)(x / getSquareWidth()) - 1;
      int r = 8 - (int)(y / getSquareHeight());
      set(c, r);
   }
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setBoardWidthHeight(int widthBoard, int heightBoard)
   {
      if (widthBoard < 0 || heightBoard < 0)
         return;
      squareWidth = (double)widthBoard / 10.0; // 8 squares + 2 spaces
      squareHeight = (double)heightBoard / 10.0;
   }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(-1) {}
   void adjustRow(int dRow) {}
   void adjustCol(int dCol) {}
   const Position& operator += (const Delta& rhs) 
   {
      int c = getCol() + rhs.dCol;
      int r = getRow() + rhs.dRow;
      
      if (c < 0 || c >= 8 || r < 0 || r >= 8)
         set(-1, -1);
      else
         set(c, r);

      return *this;
   }
   Position operator + (const Delta& rhs) const { return *this; }

private:
   void set(uint8_t colRowNew) { this->colRow = colRowNew; }

   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream& operator << (ostream& out, const Position& pos);
istream& operator >> (istream& in, Position& pos);

