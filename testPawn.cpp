/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board move forward one space: b4 --> b5
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 3, true);   // b4
   board.board[1][3] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   Move expected(Position("b4"), Position("b5"), SPACE, Move::MOVE, true);
   assertUnit(moves.count(expected) == 1);

   // TEARDOWN
   board.board[1][3] = nullptr;
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board move forward one space: b4 --> b3
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 3, false);   // b4
   board.board[1][3] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   Move expected(Position("b4"), Position("b3"), SPACE, Move::MOVE, false);
   assertUnit(moves.count(expected) == 1);

   // TEARDOWN
   board.board[1][3] = nullptr;
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance: b2 --> b4 as well as b2 --> b3
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 1, true);   // b2
   board.board[1][1] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   Move one(Position("b2"), Position("b3"), SPACE, Move::MOVE, true);
   Move two(Position("b2"), Position("b4"), SPACE, Move::MOVE, true);
   assertUnit(moves.count(one) == 1);
   assertUnit(moves.count(two) == 1);

   // TEARDOWN
   board.board[1][1] = nullptr;
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance: c7 --> c5 as well as c7 --> c5
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 6, false);   // c7
   board.board[2][6] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   Move one(Position("c7"), Position("c6"), SPACE, Move::MOVE, false);
   Move two(Position("c7"), Position("c5"), SPACE, Move::MOVE, false);
   assertUnit(moves.count(one) == 1);
   assertUnit(moves.count(two) == 1);

   // TEARDOWN
   board.board[2][6] = nullptr;
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move white pawn b6 and capture two: a7 and c7. b7 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7
 * 6    (p)              6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 5, true);            // b6
   board.board[1][5] = &pawn;

   Black a7(PAWN), b7(PAWN), c7(PAWN);
   board.board[0][6] = &a7;  // a7
   board.board[1][6] = &b7;  // b7 (blocks)
   board.board[2][6] = &c7;  // c7
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   Move ma(Position("b6"), Position("a7"), PAWN, Move::MOVE, true);
   Move mc(Position("b6"), Position("c7"), PAWN, Move::MOVE, true);
   assertUnit(moves.count(ma) == 1);
   assertUnit(moves.count(mc) == 1);

   // TEARDOWN
   board.board[1][5] = nullptr;
   board.board[0][6] = nullptr;
   board.board[1][6] = nullptr;
   board.board[2][6] = nullptr;
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move black pawn b6 and capture two: a5 and c5. b5 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6
 * 5   p p p             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 5, false);     // b6
   board.board[1][5] = &pawn;

   White a5(PAWN), b5(PAWN), c5(PAWN);
   board.board[0][4] = &a5;  // a5
   board.board[1][4] = &b5;  // b5 (blocks)
   board.board[2][4] = &c5;  // c5
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   Move ma(Position("b6"), Position("a5"), PAWN, Move::MOVE, false);
   Move mc(Position("b6"), Position("c5"), PAWN, Move::MOVE, false);
   assertUnit(moves.count(ma) == 1);
   assertUnit(moves.count(mc) == 1);

   // TEARDOWN
   board.board[1][5] = nullptr;
   board.board[0][4] = nullptr;
   board.board[1][4] = nullptr;
   board.board[2][4] = nullptr;
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant: white b5 can capture a5 and c5. Note that b6 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   // SETUP
   BoardEmpty board;
   // place our white pawn on b5
   Pawn whiteB5(1, 4, true);
   board.board[1][4] = &whiteB5;

   // place an enemy pawn that moved from c7 to c5
   Pawn blackC5(2, 4, false);
   board.board[2][4] = &blackC5;

   // block straight advance with a pawn on b6
   Pawn blockerB6(1, 5, true);
   board.board[1][5] = &blockerB6;

   // simulate that blackC5 just made its two-step move on turn #1
   board.setCurrentMove(1);
   blackC5.setLastMove(board.getCurrentMove());

   // now white to move on turn #2
   board.setCurrentMove(2);
   set<Move> moves;

   // EXERCISE
   whiteB5.getMoves(moves, board);

   // VERIFY
   // only one en-passant capture: b5 to c6
   assertUnit(moves.size() == 1);

   Move ep(Position("b5"), Position("c6"), PAWN, Move::ENPASSANT, true);
   assertUnit(moves.count(ep) == 1);

   // TEARDOWN
   board.board[1][4] = nullptr;
   board.board[2][4] = nullptr;
   board.board[1][5] = nullptr;
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant black f4 can capture e4 and g4. Note that f3 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn blackF4(5, 3, false);
   board.board[5][3] = &blackF4;

   // place a white pawn on g4 that just came from g2 to g4
   Pawn whiteG4(6, 3, true);
   board.board[6][3] = &whiteG4;

   // block straight advance with pawn on f3
   Pawn blockerF3(5, 2, true);
   board.board[5][2] = &blockerF3;

   // simulate g2?g4 on turn #1
   board.setCurrentMove(1);
   whiteG4.setLastMove(board.getCurrentMove());

   // now black to move on turn #2
   board.setCurrentMove(2);
   set<Move> moves;

   // EXERCISE
   blackF4.getMoves(moves, board);

   // VERIFY
   // only one en-passant capture: f4 to g3
   assertUnit(moves.size() == 1);
   Move ep(Position("f4"), Position("g3"), PAWN, Move::ENPASSANT, false);
   assertUnit(moves.count(ep) == 1);

   // TEARDOWN
   board.board[5][3] = nullptr;
   board.board[6][3] = nullptr;
   board.board[5][2] = nullptr;
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: white pawn b7 can capture two pawns: a8 and c8. 
 *            It can also move into b8. All three are promoted to queen
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   P . P             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn wp(1, 6, true);   // b7
   board.board[1][6] = &wp;

   // enemy pieces on a8, c8
   Black enemyA8(ROOK); board.board[0][7] = &enemyA8;
   Black enemyC8(ROOK); board.board[2][7] = &enemyC8;

   // EXERCISE
   set<Move> moves;
   wp.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);

   // straight promotion
   Move m1(Position("b7"), Position("b8"), SPACE, Move::MOVE, true);
   m1.setPromote(QUEEN);
   // left capture promotion
   Move m2(Position("b7"), Position("a8"), ROOK, Move::MOVE, true);
   m2.setPromote(QUEEN);
   // right capture promotion
   Move m3(Position("b7"), Position("c8"), ROOK, Move::MOVE, true);
   m3.setPromote(QUEEN);

   assertUnit(moves.count(m1) == 1);
   assertUnit(moves.count(m2) == 1);
   assertUnit(moves.count(m3) == 1);

   // TEARDOWN
   board.board[1][6] = nullptr;
   board.board[0][7] = nullptr;
   board.board[2][7] = nullptr;
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: black pawn e2 can capture two rooks: d1 and f1.
 *            It can also move into e1. All three are promoted to queen
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r   r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn bp(4, 1, false);   // e2
   board.board[4][1] = &bp;

   // enemy rooks on d1, f1
   White enemyD1(ROOK); board.board[3][0] = &enemyD1;
   White enemyF1(ROOK); board.board[5][0] = &enemyF1;
   set<Move> moves;

   // EXERCISE
   bp.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);

   Move m1(Position("e2"), Position("e1"), SPACE, Move::MOVE, false);
   m1.setPromote(QUEEN);
   Move m2(Position("e2"), Position("d1"), ROOK, Move::MOVE, false);
   m2.setPromote(QUEEN);
   Move m3(Position("e2"), Position("f1"), ROOK, Move::MOVE, false);
   m3.setPromote(QUEEN);

   assertUnit(moves.count(m1) == 1);
   assertUnit(moves.count(m2) == 1);
   assertUnit(moves.count(m3) == 1);

   // TEARDOWN
   board.board[4][1] = nullptr;
   board.board[3][0] = nullptr;
   board.board[5][0] = nullptr;
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   // SETUP
   Pawn pawn(0, 0, true);

   // EXERCISE
   PieceType pt = pawn.getType();

   // VERIFY
   assertUnit(pt == PAWN);

   // TEARDOWN
}