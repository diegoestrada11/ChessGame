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
   Rook rook(2, 1, true);          // c2
   board.board[2][1] = &rook;      // col=2, row=1

   White left(PAWN);
   board.board[1][1] = &left;      // b2

   White down(PAWN);
   board.board[2][0] = &down;      // c1

   White up(PAWN);
   board.board[2][2] = &up;        // c3

   White right(PAWN);
   board.board[3][1] = &right;     // d2

   set<Move> moves;

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
   Rook rook(2, 1, true);         // c2
   board.board[1][2] = &rook;
   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

   // horizontal left
   Move m1(Position("c2"), Position("b2"), SPACE, Move::MOVE, true);
   Move m2(Position("c2"), Position("a2"), SPACE, Move::MOVE, true);
   // horizontal right
   Move m3(Position("c2"), Position("d2"), SPACE, Move::MOVE, true);
   Move m4(Position("c2"), Position("e2"), SPACE, Move::MOVE, true);
   Move m5(Position("c2"), Position("f2"), SPACE, Move::MOVE, true);
   Move m6(Position("c2"), Position("g2"), SPACE, Move::MOVE, true);
   Move m7(Position("c2"), Position("h2"), SPACE, Move::MOVE, true);
   // vertical up
   Move m8(Position("c2"), Position("c3"), SPACE, Move::MOVE, true);
   Move m9(Position("c2"), Position("c4"), SPACE, Move::MOVE, true);
   Move m10(Position("c2"), Position("c5"), SPACE, Move::MOVE, true);
   Move m11(Position("c2"), Position("c6"), SPACE, Move::MOVE, true);
   Move m12(Position("c2"), Position("c7"), SPACE, Move::MOVE, true);
   Move m13(Position("c2"), Position("c8"), SPACE, Move::MOVE, true);
   // vertical down
   Move m14(Position("c2"), Position("c1"), SPACE, Move::MOVE, true);

   assertUnit(moves.find(m1) != moves.end());
   assertUnit(moves.find(m2) != moves.end());
   assertUnit(moves.find(m3) != moves.end());
   assertUnit(moves.find(m4) != moves.end());
   assertUnit(moves.find(m5) != moves.end());
   assertUnit(moves.find(m6) != moves.end());
   assertUnit(moves.find(m7) != moves.end());
   assertUnit(moves.find(m8) != moves.end());
   assertUnit(moves.find(m9) != moves.end());
   assertUnit(moves.find(m10) != moves.end());
   assertUnit(moves.find(m11) != moves.end());
   assertUnit(moves.find(m12) != moves.end());
   assertUnit(moves.find(m13) != moves.end());
   assertUnit(moves.find(m14) != moves.end());

   // TEARDOWN
   board.board[1][2] = nullptr;
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
   // SETUP: everything now board.board[col][row]
   BoardEmpty board;
   Rook rook(2, 1, true);          // c2
   board.board[2][1] = &rook;      // col=2, row=1

   White pLeft(PAWN);
   board.board[0][1] = &pLeft;     // a2

   White pDown(PAWN);
   board.board[2][0] = &pDown;     // c1

   White pUp(PAWN);
   board.board[2][7] = &pUp;       // c8

   White pRight(PAWN);
   board.board[7][1] = &pRight;    // h2

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 10);

   // left
   assertUnit(moves.count(Move(Position("c2"), Position("b2"), SPACE, Move::MOVE, true)));
   // right until before h2
   assertUnit(moves.count(Move(Position("c2"), Position("d2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("e2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("f2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("g2"), SPACE, Move::MOVE, true)));
   // up until before c8
   assertUnit(moves.count(Move(Position("c2"), Position("c3"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c4"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c5"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c6"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c7"), SPACE, Move::MOVE, true)));

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[0][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][7] = nullptr;
   board.board[7][1] = nullptr;
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
   Rook rook(2, 1, true);         // c2
   board.board[1][2] = &rook;

   Black pLeft(PAWN);   board.board[1][0] = &pLeft;  // a2
   Black pDown(PAWN);   board.board[0][2] = &pDown;  // c1
   Black pUp(PAWN);     board.board[7][2] = &pUp;    // c8
   Black pRight(PAWN);  board.board[1][7] = &pRight; // h2

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

   // slides
   assertUnit(moves.count(Move(Position("c2"), Position("b2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("d2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("e2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("f2"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("g2"), SPACE, Move::MOVE, true)));
   // captures
   assertUnit(moves.count(Move(Position("c2"), Position("a2"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("h2"), PAWN, Move::MOVE, true)));
   // vertical slides
   assertUnit(moves.count(Move(Position("c2"), Position("c3"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c4"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c5"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c6"), SPACE, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c7"), SPACE, Move::MOVE, true)));
   // captures
   assertUnit(moves.count(Move(Position("c2"), Position("c1"), PAWN, Move::MOVE, true)));
   assertUnit(moves.count(Move(Position("c2"), Position("c8"), PAWN, Move::MOVE, true)));

   // TEARDOWN
   board.board[1][2] = nullptr;
   board.board[1][0] = nullptr;
   board.board[0][2] = nullptr;
   board.board[7][2] = nullptr;
   board.board[1][7] = nullptr;
}

/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   // SETUP
   Rook rook(2, 1, true);

   // EXERCISE
   PieceType pt = rook.getType();

   // VERIFY
   assertUnit(pt == ROOK);

   // TEARDOWN
}
