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

   // EXERCISE
   std::set<Move> moves;
   pawn.getMoves(moves, board);

   // VERIFY
   // Expect exactly one move: b4 -> b5
   assertUnit(moves.size() == 1);

   // Construct the expected Move and verify it's in the set
   Move expected(
      Position(1, 3),   // from b4
      Position(1, 4),   // to   b5
      SPACE,            // no capture
      Move::MOVE,       // normal pawn move
      true              // white to move
   );
   assertUnit(moves.find(expected) != moves.end());

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
   Pawn pawn(1, 3, false);   // b4, black pawn
   board.board[1][3] = &pawn;

   // EXERCISE
   std::set<Move> moves;
   pawn.getMoves(moves, board);

   // VERIFY
   // Expect exactly one move: b4 -> b3
   assertUnit(moves.size() == 1);

   Move expected(
      Position(1, 3),   // from b4
      Position(1, 2),   // to   b3
      SPACE,            // no capture
      Move::MOVE,       // normal pawn move
      false             // black to move
   );
   assertUnit(moves.find(expected) != moves.end());

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

   // EXERCISE
   std::set<Move> moves;
   pawn.getMoves(moves, board);

   // VERIFY
   // Expect two moves: b2 -> b3 and b2 -> b4
   assertUnit(moves.size() == 2);

   Move advanceOne(
      Position(1, 1),   // from b2
      Position(1, 2),   // to   b3
      SPACE,            // no capture
      Move::MOVE,       // normal pawn move
      true              // white to move
   );
   Move advanceTwo(
      Position(1, 1),   // from b2
      Position(1, 3),   // to   b4
      SPACE,
      Move::MOVE,
      true
   );
   assertUnit(moves.find(advanceOne) != moves.end());
   assertUnit(moves.find(advanceTwo) != moves.end());

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

   // EXERCISE
   std::set<Move> moves;
   pawn.getMoves(moves, board);

   // VERIFY
   // Expect two moves: c7 -> c6 and c7 -> c5
   assertUnit(moves.size() == 2);

   Move advanceOne(
      Position(2, 6),   // from c7
      Position(2, 5),   // to   c6
      SPACE,            // no capture
      Move::MOVE,       // normal pawn move
      false             // black to move
   );
   Move advanceTwo(
      Position(2, 6),   // from c7
      Position(2, 4),   // to   c5
      SPACE,
      Move::MOVE,
      false
   );
   assertUnit(moves.find(advanceOne) != moves.end());
   assertUnit(moves.find(advanceTwo) != moves.end());

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

   // Place opposing pawns to capture
   Black blackA7(PAWN), blackB7(PAWN), blackC7(PAWN);
   board.board[0][6] = &blackA7; // a7
   board.board[1][6] = &blackB7; // b7 (blocks forward)
   board.board[2][6] = &blackC7; // c7

   // EXERCISE
   std::set<Move> moves;
   pawn.getMoves(moves, board);

   // VERIFY
   // Only two captures (diagonals), no forward move
   assertUnit(moves.size() == 2);

   Move captureA7(
      Position(1, 5),   // from b6
      Position(0, 6),   // to   a7
      PAWN,             // capture pawn
      Move::MOVE,       // normal move type
      true              // white to move
   );
   Move captureC7(
      Position(1, 5),   // from b6
      Position(2, 6),   // to   c7
      PAWN,
      Move::MOVE,
      true
   );
   assertUnit(moves.find(captureA7) != moves.end());
   assertUnit(moves.find(captureC7) != moves.end());

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
   Pawn pawn(1, 5, false);     // b6, black pawn
   board.board[1][5] = &pawn;

   // Place opposing white pawns
   White whiteA5(PAWN), whiteB5(PAWN), whiteC5(PAWN);
   board.board[0][4] = &whiteA5; // a5
   board.board[1][4] = &whiteB5; // b5 (blocks forward)
   board.board[2][4] = &whiteC5; // c5

   // EXERCISE
   std::set<Move> moves;
   pawn.getMoves(moves, board);

   // VERIFY
   // Only two captures (diagonals), no forward move
   assertUnit(moves.size() == 2);

   Move captureA5(
      Position(1, 5),   // from b6
      Position(0, 4),   // to   a5
      PAWN,             // captured pawn
      Move::MOVE,       // normal move
      false             // black to move
   );
   Move captureC5(
      Position(1, 5),   // from b6
      Position(2, 4),   // to   c5
      PAWN,
      Move::MOVE,
      false
   );
   assertUnit(moves.find(captureA5) != moves.end());
   assertUnit(moves.find(captureC5) != moves.end());

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
   assertUnit(NOT_YET_IMPLEMENTED);
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
   assertUnit(NOT_YET_IMPLEMENTED);
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
   assertUnit(NOT_YET_IMPLEMENTED);
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
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

