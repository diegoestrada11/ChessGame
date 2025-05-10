/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "position.h"
#include "piece.h"
#include <cassert>
using namespace std;


// we really REALLY need to delete this.
Space space;

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   Piece* p = board[pos.getCol()][pos.getRow()];
   return p ? *p : space;
}
Piece& Board::operator [] (const Position& pos)
{
   Piece* p = board[pos.getCol()][pos.getRow()];
   return p ? *p : space;
}


/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr)
{
   pSpace = new Space;
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}