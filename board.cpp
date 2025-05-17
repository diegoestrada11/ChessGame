/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   if (fFree)
      free();

   // clear all squares
   for (int c = 0; c < 8; ++c)
      for (int r = 0; r < 8; ++r)
         board[c][r] = nullptr;

   //for (int c = 0; c < 8; ++c)
   //   board[c][1] = new Pawn(c, 1, true);

   //// Black pawns (row 6)
   //for (int c = 0; c < 8; ++c)
   //   board[c][6] = new Pawn(c, 6, false);

   board[1][0] = new Knight(0, 1, true);
   board[6][0] = new Knight(0, 6, true);
   board[6][7] = new Knight(7, 6, false);
   board[1][7] = new Knight(7, 1, false);


   // Start move counter at zero
   numMoves = 0;
}
Space space(0, 0);

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

/***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position& posHover, const Position& posSelect) const
{
   pgout->drawBoard();
   pgout->drawKnight({ 1,0 }, true);
   pgout->drawKnight({ 6,0 }, true);
   pgout->drawKnight({ 1,7 }, false);
   pgout->drawKnight({ 6,7 }, false);
   //// draw each piece that’s present

   //for (int c = 0; c < 8; ++c)
   //{
   //   for (int r = 0; r < 8; ++r)
   //   {
   //      Piece* p = board[c][r];
   //      if (p && p->getType() == KNIGHT)    // only knights
   //      {
   //         p->display(pgout);
   //      }
   //   }
   //}

}

/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   if (!noreset)
      reset();

}

/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int c = 0; c < 8; ++c)
      for (int r = 0; r < 8; ++r)
      {
         delete board[c][r];
         board[c][r] = nullptr;
      }
}

/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard() const
{
   for (int c = 0; c < 8; ++c)
      for (int r = 0; r < 8; ++r)
      {
         if (board[c][r])
         {
            Position pos = board[c][r]->getPosition();
            assert(pos.getCol() == c && pos.getRow() == r);
         }
      }

}

/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move& move)
{
   // advance global move count
   ++numMoves;

   Position src = move.getSource();
   Position dst = move.getDest();
   int sc = src.getCol(), sr = src.getRow();
   int dc = dst.getCol(), dr = dst.getRow();

   Piece* p = board[sc][sr];
   if (!p)
      return;   

   // only delete a captured piece if it is *not* a PieceSpy
   if (move.getCapture() != SPACE)
   {
      // if this is not a spy, delete it; spies should stay alive
      if (dynamic_cast<PieceSpy*>(board[dc][dr]) == nullptr)
         delete board[dc][dr];
   }

   board[dc][dr] = p;

   board[sc][sr] = new Space(sc, sr);

   p->setLastMove(numMoves);

}

/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(new Space(0,0)), moveNumber(0){}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}