/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   Rook rook(2, 1, true); // c2, white rook
   board.board[2][1] = &rook;

   White white(PAWN);
   board.board[1][1] = &white;  // b2 left
   board.board[2][0] = &white;  // c1 down
   board.board[2][2] = &white;  // c3 up
   board.board[3][1] = &white;  // d2 right

   std::set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[1][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][2] = nullptr;
   board.board[3][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, true /*white*/); // temp values
   rook.position.set(1, 1); // b2
   board.board[1][1] = &rook;

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

   // TEARDOWN
   board.board[1][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, true /*white*/);
   rook.position.set(1, 1); // b2
   board.board[1][1] = &rook;

   White pawn1(PAWN);
   White pawn2(PAWN);
   White pawn3(PAWN);
   White pawn4(PAWN);

   board.board[1][7] = &pawn1;  // b8
   board.board[1][0] = &pawn2;  // b1
   board.board[0][1] = &pawn3;  // a2
   board.board[7][1] = &pawn4;  // h2

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

   // TEARDOWN
   board.board[1][1] = nullptr; // Rook
   board.board[1][7] = nullptr; // Pawn b8
   board.board[1][0] = nullptr; // Pawn b1
   board.board[0][1] = nullptr; // Pawn a2
   board.board[7][1] = nullptr; // Pawn h2
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, true /*white*/);
   rook.position.set(1, 1); // b2
   board.board[1][1] = &rook;

   White pawn1(PAWN);
   White pawn2(PAWN);
   White pawn3(PAWN);
   White pawn4(PAWN);

   // Friendly pawns blocking rook's path — same color as rook
   board.board[1][7] = &pawn1;  // b8
   board.board[1][0] = &pawn2;  // b1
   board.board[0][1] = &pawn3;  // a2
   board.board[7][1] = &pawn4;  // h2

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

   // TEARDOWN
   board.board[1][1] = nullptr; // Rook
   board.board[1][7] = nullptr; // Pawn b8
   board.board[1][0] = nullptr; // Pawn b1
   board.board[0][1] = nullptr; // Pawn a2
   board.board[7][1] = nullptr; // Pawn h2
}

/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   Rook rook(0, 0, true);
   assertUnit(rook.getType() == ROOK);
}
