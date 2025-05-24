/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   // Place a white king at d5 (col=3, row=4)
   King king(3, 4, true);
   board.board[3][4] = &king;

   // Surround it with friendly white pawns
   White pawnC6(PAWN); board.board[2][5] = &pawnC6;  // c6
   White pawnD6(PAWN); board.board[3][5] = &pawnD6;  // d6
   White pawnE6(PAWN); board.board[4][5] = &pawnE6;  // e6

   White pawnC5(PAWN); board.board[2][4] = &pawnC5;  // c5
   White pawnE5(PAWN); board.board[4][4] = &pawnE5;  // e5

   White pawnC4(PAWN); board.board[2][3] = &pawnC4;  // c4
   White pawnD4(PAWN); board.board[3][3] = &pawnD4;  // d4
   White pawnE4(PAWN); board.board[4][3] = &pawnE4;  // e4

   std::set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);

   // TEARDOWN
   board.board[3][4] = nullptr; // King

   board.board[2][5] = nullptr; // c6
   board.board[3][5] = nullptr; // d6
   board.board[4][5] = nullptr; // e6

   board.board[2][4] = nullptr; // c5
   board.board[4][4] = nullptr; // e5

   board.board[2][3] = nullptr; // c4
   board.board[3][3] = nullptr; // d4
   board.board[4][3] = nullptr; // e4
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
   // SETUP
   BoardEmpty board;

   // Place a white king at d5 (col=3, row=4)
   King king(3, 4, true);
   board.board[3][4] = &king;

   // Surround it with enemy black pawns so king can capture
   Black pawnC6(PAWN); board.board[2][5] = &pawnC6;  // c6
   Black pawnD6(PAWN); board.board[3][5] = &pawnD6;  // d6
   Black pawnE6(PAWN); board.board[4][5] = &pawnE6;  // e6

   Black pawnC5(PAWN); board.board[2][4] = &pawnC5;  // c5
   Black pawnE5(PAWN); board.board[4][4] = &pawnE5;  // e5

   Black pawnC4(PAWN); board.board[2][3] = &pawnC4;  // c4
   Black pawnD4(PAWN); board.board[3][3] = &pawnD4;  // d4
   Black pawnE4(PAWN); board.board[4][3] = &pawnE4;  // e4

   std::set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   // The king should be able to capture all 8 surrounding pawns
   assertUnit(moves.size() == 8);

   // Optionally verify each expected move is in moves (left as exercise)

   // TEARDOWN
   board.board[3][4] = nullptr; // King

   board.board[2][5] = nullptr; // c6
   board.board[3][5] = nullptr; // d6
   board.board[4][5] = nullptr; // e6

   board.board[2][4] = nullptr; // c5
   board.board[4][4] = nullptr; // e5

   board.board[2][3] = nullptr; // c4
   board.board[3][3] = nullptr; // d4
   board.board[4][3] = nullptr; // e4
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


