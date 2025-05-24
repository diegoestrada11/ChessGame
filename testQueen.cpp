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

   Queen queen(2, 1, true);    // c2
   board.board[2][1] = &queen;

   // surround on all 8 directions
   White pL(PAWN);  board.board[1][1] = &pL;  // b2
   White pR(PAWN);  board.board[3][1] = &pR;  // d2
   White pU(PAWN);  board.board[2][2] = &pU;  // c3
   White pD(PAWN);  board.board[2][0] = &pD;  // c1
   White pUL(PAWN); board.board[1][2] = &pUL; // b3
   White pUR(PAWN); board.board[3][2] = &pUR; // d3
   White pDL(PAWN); board.board[1][0] = &pDL; // b1
   White pDR(PAWN); board.board[3][0] = &pDR; // d1

   set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.empty());

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[1][1] = nullptr;
   board.board[3][1] = nullptr;
   board.board[2][2] = nullptr;
   board.board[2][0] = nullptr;
   board.board[1][2] = nullptr;
   board.board[3][2] = nullptr;
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
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
   Queen queen(2, 1, true);    // c2
   board.board[2][1] = &queen;

   set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 23);

   // TEARDOWN
   board.board[2][1] = nullptr;
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
   Queen queen(2, 1, true);   // c2
   board.board[2][1] = &queen;

   // friendly pawns blocking on the very first square in each of the 8 directions
   White pA2(PAWN); board.board[0][1] = &pA2;  // a2 (left)
   White pA4(PAWN); board.board[0][3] = &pA4;  // a4 (up-left)
   White pB1(PAWN); board.board[1][0] = &pB1;  // b1 (down-left)
   White pC1(PAWN); board.board[2][0] = &pC1;  // c1 (down)
   White pC8(PAWN); board.board[2][7] = &pC8;  // c8 (up)
   White pD1(PAWN); board.board[3][0] = &pD1;  // d1 (down-right)
   White pH2(PAWN); board.board[7][1] = &pH2;  // d2 (right)
   White ph7(PAWN); board.board[7][6] = &ph7;  // d3 (up-right)

   set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 15);
   assertUnit(moves.count(Move(Position("c2"), Position("b2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("b3"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c3"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c4"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c5"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c6"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c7"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("d2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("d3"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("e2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("e4"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("f2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("f5"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("g2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("g6"), PAWN, Move::MOVE, true)));

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[0][1] = nullptr;
   board.board[0][3] = nullptr;
   board.board[1][0] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][7] = nullptr;
   board.board[3][0] = nullptr;
   board.board[3][1] = nullptr;
   board.board[3][2] = nullptr;
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
   Queen queen(2, 1, true);   // c2
   board.board[2][1] = &queen;

   // enemy pawns as first encounter in each direction
   Black pA2(PAWN); board.board[0][1] = &pA2;  // a2 (left)
   Black pA4(PAWN); board.board[0][3] = &pA4;  // a4 (up-left)
   Black pB1(PAWN); board.board[1][0] = &pB1;  // b1 (down-left)
   Black pC1(PAWN); board.board[2][0] = &pC1;  // c1 (down)
   Black pC8(PAWN); board.board[2][7] = &pC8;  // c8 (up)
   Black pD1(PAWN); board.board[3][0] = &pD1;  // d1 (down-right)
   Black pH2(PAWN); board.board[7][1] = &pH2;  // h2 (right)
   Black pH7(PAWN); board.board[7][6] = &pH7;  // h7 (up-right)

   std::set<Move> moves;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   // 8 captures, no slide beyond them
   assertUnit(moves.size() == 23);
   assertUnit(moves.count(Move(Position("c2"), Position("a2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("a4"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("b1"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c1"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c8"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("d1"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("h2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("h7"), PAWN, Move::MOVE, true)));

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[0][1] = nullptr;
   board.board[0][3] = nullptr;
   board.board[1][0] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][7] = nullptr;
   board.board[3][0] = nullptr;
   board.board[7][1] = nullptr;
   board.board[7][6] = nullptr;
}

/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   // SETUP
   Queen queen(2, 1, false);

   // EXERCISE
   PieceType pt = queen.getType();

   // VERIFY
   assertUnit(pt == QUEEN);

   // TEARDOWN
}
