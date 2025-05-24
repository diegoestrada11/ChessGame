/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Natalia Navarrete, Diego Estrada
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
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

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
class TestKnight;
class TestBoard;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
   friend class TestKnight;
   friend class TestBoard;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs) : colRow(0) { set(rhs.colRow); }
   Position() : colRow(0xff) {}
   bool isInvalid() const { return (colRow & 0x88) ? true : false; }
   bool isValid()   const { return !isInvalid(); }
   void setValid() 
   { 
      if (isInvalid())
         set(0xff);
   }
   void setInvalid() { set(0xff); }
   bool operator <  (const Position& rhs) const 
                     { return colRow < rhs.colRow; }
   bool operator == (const Position& rhs) const 
   {
      if (isInvalid())
         return rhs.isInvalid();
      else
         return rhs.colRow == colRow;
   }
   bool operator != (const Position& rhs) const                   
   { 
      if (isInvalid())
         return rhs.isValid();
      else
         return rhs.colRow != colRow;
   }
   const Position& operator =  (const Position& rhs);

   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(0xff) { setLocation(location); }
   int getLocation() const { return getRow() * 8 + getCol(); }
   void setLocation(int location) 
   {
      if (0 <= location && location <64)
         set(location % 8, location / 8);
      else
         set(0xff);
   }


   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow(0x00) { set(c, r); }
   virtual int getCol() const { return isInvalid() ? -1 : (int)((colRow & 0xf0) >> 4);}
   virtual int getRow() const { return isInvalid() ? -1 : (int)((colRow & 0x0f) >> 0); }
   void setRow(int r)         
   {
      if (r >= 0 && r < 8)
         set((colRow & 0xf0) + (char)r);
      else
         set(0xff);
   }
   void setCol(int c)         
   {
      if (c >= 0 && c < 8)
         set(((c & 0x0f) << 4) | (colRow & 0x0f));
      else
         set(0xff);
   }
   void set(int c, int r);

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x00) { *this = s; }
   const Position& operator =  (const char* rhs);
   const Position& operator =  (const string& rhs) 
   {
      *this = rhs.c_str();  return *this;
   }

   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const
      { return int((getCol() + 1) * getSquareWidth());   }
   int getY()   const
   { return int((getRow() + 1) * getSquareHeight()); }
   int getScreenX() const {
      return getX() + OFFSET_BOARD;
   }
   int getScreenY() const {
      return getY() + OFFSET_BOARD;
   }

   void setXY(double x, double y) {
      int col1 = int(x / getSquareWidth());    // yields 1…8 if on board
      int row1 = int(y / getSquareHeight());   // yields 1…8 if on board

      // Convert to 0-based and flip Y so row0 is bottom:
      int c = col1 - 1;
      int r = 8 - row1;

      // Clamp exactly to what the tests expect:
      if (c < 0 || c >= 8) {
         // completely off horizontally ? fully invalid
         set(0xff);
      }
      else if (r < 0 || r >= 8) {
         // column was ok, row off vertically ? invalid row nibble only
         set((c << 4) | 0x0f);
      }
      else {
         // fully valid square
         set(c, r);
      }
   }
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setSquareWidth(double width)
   {
      if (width > 0.0)
         squareWidth = width;
   }
   void setSquareHeight(double height)
   {
      if (height > 0.0)
         squareHeight = height;
   }
   void setBoardWidthHeight(int widthBoard, int heightBoard);

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(-1) 
   {
      set(rhs.getCol() + delta.dCol, rhs.getRow() + delta.dRow);
   }
   void adjustRow(int dRow) 
   {
      if (isValid())
         setRow(getRow() + (char)dRow);
   }
   void adjustCol(int dCol) 
   {
      if (isValid())
         setCol(getCol() + (char)dCol);
   }
   const Position& operator += (const Delta& rhs);
   Position operator + (const Delta& rhs) const { return *this; }

private:
   void set(uint8_t colRowNew) { this->colRow = colRowNew; }

   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream& operator << (ostream& out, const Position& pos);
istream& operator >> (istream& in, Position& pos);

