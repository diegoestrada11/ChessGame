/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
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
 * 3     p   p           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(2, 1, true);        // c2
   board.board[2][1] = &bishop;

   White pb1(PAWN); board.board[1][0] = &pb1;  // b1
   White pd1(PAWN); board.board[3][0] = &pd1;  // d1
   White pb3(PAWN); board.board[1][2] = &pb3;  // b3
   White pd3(PAWN); board.board[3][2] = &pd3;  // d3

   set<Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[1][2] = nullptr;
   board.board[3][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(2, 1, true);   // c2
   board.board[2][1] = &bishop;
   set<Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);

   Move c2d3(Position("c2"), Position("d3"), SPACE, Move::MOVE, true);
   Move c2e4(Position("c2"), Position("e4"), SPACE, Move::MOVE, true);
   Move c2f5(Position("c2"), Position("f5"), SPACE, Move::MOVE, true);
   Move c2g6(Position("c2"), Position("g6"), SPACE, Move::MOVE, true);
   Move c2h7(Position("c2"), Position("h7"), SPACE, Move::MOVE, true);

   Move c2b3(Position("c2"), Position("b3"), SPACE, Move::MOVE, true);
   Move c2a4(Position("c2"), Position("a4"), SPACE, Move::MOVE, true);

   Move c2d1(Position("c2"), Position("d1"), SPACE, Move::MOVE, true);
   Move c2b1(Position("c2"), Position("b1"), SPACE, Move::MOVE, true);

   assertUnit(moves.find(c2d3) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2h7) != moves.end());

   assertUnit(moves.find(c2b3) != moves.end());
   assertUnit(moves.find(c2a4) != moves.end());

   assertUnit(moves.find(c2d1) != moves.end());
   assertUnit(moves.find(c2b1) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(2, 1, true);   // c2
   board.board[2][1] = &bishop;

   White pb1(PAWN); board.board[1][0] = &pb1;  // b1
   White pd1(PAWN); board.board[3][0] = &pd1;  // d1
   White pa4(PAWN); board.board[0][3] = &pa4;  // a4
   White ph7(PAWN); board.board[7][6] = &ph7;  // h7

   set<Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 5);

   Move c2d3(Position("c2"), Position("d3"), SPACE, Move::MOVE, true);
   Move c2e4(Position("c2"), Position("e4"), SPACE, Move::MOVE, true);
   Move c2f5(Position("c2"), Position("f5"), SPACE, Move::MOVE, true);
   Move c2g6(Position("c2"), Position("g6"), SPACE, Move::MOVE, true);
   Move c2b3(Position("c2"), Position("b3"), SPACE, Move::MOVE, true);

   assertUnit(moves.find(c2d3) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2b3) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[0][3] = nullptr;
   board.board[7][6] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(2, 1, true);   // c2
   board.board[2][1] = &bishop;

   Black pb1(PAWN); board.board[1][0] = &pb1;  // b1
   Black pd1(PAWN); board.board[3][0] = &pd1;  // d1
   Black pa4(PAWN); board.board[0][3] = &pa4;  // a4
   Black ph7(PAWN); board.board[7][6] = &ph7;  // h7

   set<Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);

   // slides
   Move c2d3(Position("c2"), Position("d3"), SPACE, Move::MOVE, true);
   Move c2e4(Position("c2"), Position("e4"), SPACE, Move::MOVE, true);
   Move c2f5(Position("c2"), Position("f5"), SPACE, Move::MOVE, true);
   Move c2g6(Position("c2"), Position("g6"), SPACE, Move::MOVE, true);

   // captures
   Move c2h7(Position("c2"), Position("h7"), PAWN, Move::MOVE, true);
   Move c2a4(Position("c2"), Position("a4"), PAWN, Move::MOVE, true);
   Move c2d1(Position("c2"), Position("d1"), PAWN, Move::MOVE, true);
   Move c2b1(Position("c2"), Position("b1"), PAWN, Move::MOVE, true);

   assertUnit(moves.find(c2d3) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2h7) != moves.end());
   assertUnit(moves.find(c2a4) != moves.end());
   assertUnit(moves.find(c2d1) != moves.end());
   assertUnit(moves.find(c2b1) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[0][3] = nullptr;
   board.board[7][6] = nullptr;
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   // SETUP
   Bishop bishop(2, 1, false);

   // EXERCISE
   PieceType pt = bishop.getType();

   // VERIFY
   assertUnit(pt == BISHOP);

   // TEARDOWN
}