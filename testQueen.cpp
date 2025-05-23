/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
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
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   Queen queen(3, 1, true); // d2, white queen
   board.board[3][1] = &queen;

   White pawn1(PAWN);
   White pawn2(PAWN);
   White pawn3(PAWN);
   White pawn4(PAWN);
   White pawn5(PAWN);

   board.board[2][1] = &pawn1;  // c2 (left)
   board.board[4][1] = &pawn2;  // e2 (right)
   board.board[3][2] = &pawn3;  // d3 (up)
   board.board[3][0] = &pawn4;  // d1 (down)
   board.board[2][2] = &pawn5;  // c3 (up-left diagonal)

   std::set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);

   // TEARDOWN
   board.board[3][1] = nullptr; // queen

   board.board[2][1] = nullptr; // c2
   board.board[4][1] = nullptr; // e2
   board.board[3][2] = nullptr; // d3
   board.board[3][0] = nullptr; // d1
   board.board[2][2] = nullptr; // c3
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Queen queen(3, 1, true);  // d2 (col=3, row=1)
   board.board[3][1] = &queen;

   std::set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 7); 

   // TEARDOWN
   board.board[3][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;

   Queen queen(3, 1, true);  // d2, white
   board.board[3][1] = &queen;

   White pawnC3(PAWN); board.board[2][2] = &pawnC3;  // c3
   White pawnD3(PAWN); board.board[3][2] = &pawnD3;  // d3
   White pawnE3(PAWN); board.board[4][2] = &pawnE3;  // e3

   White pawnC2(PAWN); board.board[2][1] = &pawnC2;  // c2
   White pawnE2(PAWN); board.board[4][1] = &pawnE2;  // e2

   White pawnC1(PAWN); board.board[2][0] = &pawnC1;  // c1
   White pawnD1(PAWN); board.board[3][0] = &pawnD1;  // d1
   White pawnE1(PAWN); board.board[4][0] = &pawnE1;  // e1

   // Black pawns where queen can capture:
   Black pawnA4(PAWN); board.board[0][3] = &pawnA4;  // a4
   Black pawnB7(PAWN); board.board[1][6] = &pawnB7;  // b7
   Black pawnH2(PAWN); board.board[7][1] = &pawnH2;  // h2

   set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);

   // TEARDOWN
   board.board[3][1] = nullptr; // Queen

   board.board[2][2] = nullptr;
   board.board[3][2] = nullptr;
   board.board[4][2] = nullptr;
   board.board[2][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[4][0] = nullptr;

   board.board[0][3] = nullptr;
   board.board[1][6] = nullptr;
   board.board[7][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Queen queen(9, 9, true /*white*/);
   queen.position.set(3, 1);  // d2 (remember 0-based indexing)
   board.board[1][3] = &queen;

   White pawnA4(PAWN);  board.board[3][4] = &pawnA4;  // d5 (up)
   White pawnG7(PAWN);  board.board[6][6] = &pawnG7;  // g7 (up-right diagonal)
   White pawnA8(PAWN);  board.board[7][0] = &pawnA8;  // a8 (up-left diagonal)
   White pawnA2(PAWN);  board.board[1][0] = &pawnA2;  // a2 (left)
   White pawnG2(PAWN);  board.board[1][6] = &pawnG2;  // g2 (right)
   White pawnB1(PAWN);  board.board[0][1] = &pawnB1;  // b1 (down-left diagonal)
   White pawnD1(PAWN);  board.board[0][3] = &pawnD1;  // d1 (down)
   White pawnF1(PAWN);  board.board[0][5] = &pawnF1;  // f1 (down-right diagonal)

   std::set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() > 0);

   // TEARDOWN
   board.board[1][3] = nullptr; // Queen

   board.board[3][4] = nullptr; // pawn d5
   board.board[6][6] = nullptr; // pawn g7
   board.board[7][0] = nullptr; // pawn a8
   board.board[1][0] = nullptr; // pawn a2
   board.board[1][6] = nullptr; // pawn g2
   board.board[0][1] = nullptr; // pawn b1
   board.board[0][3] = nullptr; // pawn d1
   board.board[0][5] = nullptr; // pawn f1
}

/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   // SETUP
   Queen queen(0, 0, true); 

   // EXERCISE & VERIFY
   assertUnit(queen.getType() == QUEEN);
}
