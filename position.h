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
   bool isValid()   const;
   void setValid() {}
   void setInvalid() {}
   bool operator <  (const Position& rhs) const 
                     { return this->colRow < rhs.colRow; }
   bool operator == (const Position& rhs) const 
                     { return this->colRow == rhs.colRow; }
   bool operator != (const Position& rhs) const 
                     { return this != &rhs; }
   const Position& operator =  (const Position& rhs);

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
   void set(int c, int r);

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x99) {}
   const Position& operator =  (const char* rhs);
   const Position& operator =  (const string& rhs) 
                              { return operator=(rhs.c_str()); }

   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const
      { return (int)((double)getCol() * getSquareWidth() + getSquareWidth()); }
   int getY()   const
      { return (int)((double)getRow() * getSquareHeight() + getSquareHeight());}
   void setXY(double x, double y)
   {
      int c = (int)(x / getSquareWidth()) - 1;
      int r = 8 - (int)(y / getSquareHeight());
      set(c, r);
   }
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setBoardWidthHeight(int widthBoard, int heightBoard);

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(-1) {}
   void adjustRow(int dRow) {}
   void adjustCol(int dCol) {}
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

