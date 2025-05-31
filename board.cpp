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
#include "pieceBishop.h"
#include "pieceRook.h"
#include "pieceKing.h"
#include "pieceQueen.h"
#include "piecePawn.h"
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

   // Clear everything out
   for (int c = 0; c < 8; ++c)
      for (int r = 0; r < 8; ++r)
         board[c][r] = nullptr;

   // 2) White back rank (row 0) and pawn rank (row 1)
   board[0][0] = new Rook(0, 0, true);
   board[1][0] = new Knight(1, 0, true);
   board[2][0] = new Bishop(2, 0, true);
   board[3][0] = new Queen(3, 0, true);
   board[4][0] = new King(4, 0, true);
   board[5][0] = new Bishop(5, 0, true);
   board[6][0] = new Knight(6, 0, true);
   board[7][0] = new Rook(7, 0, true);
   for (int c = 0; c < 8; ++c)
      board[c][1] = new Pawn(c, 1, true);

   //
   // 3) Black pawn rank (row 6) and back rank (row 7)
   //
   for (int c = 0; c < 8; ++c)
      board[c][6] = new Pawn(c, 6, false);

   board[0][7] = new Rook(0, 7, false);
   board[1][7] = new Knight(1, 7, false);
   board[2][7] = new Bishop(2, 7, false);
   board[3][7] = new Queen(3, 7, false);
   board[4][7] = new King(4, 7, false);
   board[5][7] = new Bishop(5, 7, false);
   board[6][7] = new Knight(6, 7, false);
   board[7][7] = new Rook(7, 7, false);

   //
   // 4) Reset the move counter
   //
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
   // draw empty checkboard background
   pgout->drawBoard();

   // draw every square’s piece (or a space):
   for (int c = 0; c < 8; ++c)
      for (int r = 0; r < 8; ++r)
      {
         Position currentPos(c, r);
         // highlight the selected square from mouse hovering 
         if (currentPos == posHover)
         {
            pgout->drawHover(posHover);
         }

         // highlight the selected square from mouse clicking
         if (currentPos == posSelect)
         {
            pgout->drawSelected(posSelect);
         }

         Piece* p = board[c][r];
         if (p)
            p->display(pgout);
         else
            space.display(pgout);
      }


   if (posSelect.isValid())
   {
      int sc = posSelect.getCol();
      int sr = posSelect.getRow();

      Piece* selectedPiece = board[sc][sr];
      
      // Only if there really is a non-Space piece at posSelect
      if (selectedPiece != nullptr && dynamic_cast<Space*>(selectedPiece) == nullptr)
      {
         // Let the piece fill allMoves with every legal Move
         set<Move> allMoves;
         selectedPiece->getMoves(allMoves, *this);

         // For each legal move, highlight the destination square
         for (const Move& m : allMoves)
         {
            Position dest = m.getDest();
            pgout->drawPossible(dest);
         }
      }
   }
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
   if (!p) return;

   // 1) Handle castling first
   if (move.getCastleKing() || move.getCastleQueen())
   {
      // move the king
      board[dc][dr] = p;
      board[sc][sr] = new Space(sc, sr);

      // pick up the rook as well
      int rookSrc = move.getCastleKing() ? 7 : 0;
      int rookDst = move.getCastleKing() ? 5 : 3;
      Piece* rook = board[rookSrc][sr];
      board[rookDst][sr] = rook;
      board[rookSrc][sr] = new Space(rookSrc, sr);

      // stamp lastMove on both
      p->setLastMove(numMoves);
      rook->setLastMove(numMoves);
      return;
   }

   // 2) Handle pawn?promotion (pawn arrives on the far rank)
   if (p->getType() == PAWN && ((p->isWhite() && dr == 7) || (!p->isWhite() && dr == 0)))
   {
      // delete whatever was on dst (capture)
      if (move.getCapture() != SPACE)
         if (dynamic_cast<PieceSpy*>(board[dc][dr]) == nullptr)
            delete board[dc][dr];

      // delete the pawn from the source
      delete p;

      // drop in a brand new Queen
      board[dc][dr] = new Queen(dc, dr, move.getWhiteMove());
      board[sc][sr] = new Space(sc, sr);
      return;
   }

   // 3) Ordinary capture (non?promotion)
   if (move.getCapture() != SPACE)
   {
      if (dynamic_cast<PieceSpy*>(board[dc][dr]) == nullptr)
         delete board[dc][dr];
   }

   // 4) Normal single?piece move
   board[dc][dr] = p;
   board[sc][sr] = new Space(sc, sr);

   // record its new last?move
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


bool Board::isUnderAttack(const Position& pos, bool byWhite) const
{
   for (int c = 0; c < 8; ++c)
   {
      for (int r = 0; r < 8; ++r)
      {
         const Piece* piece = board[c][r];
         if (piece && piece->isWhite() == byWhite)
         {
            std::set<Move> temp;
            piece->getMoves(temp, *this);
            for (const Move& m : temp)
            {
               if (m.getDest() == pos)
                  return true;
            }
         }
      }
   }
   return false;
}
