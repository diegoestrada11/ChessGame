/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
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
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/); // we will reset all this.
   knight.fWhite = true;
   knight.position.colRow = 0x60;
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set <Move> moves;
   Move g1e2p;
   g1e2p.source.colRow = 0x60;
   g1e2p.dest.colRow = 0x41;
   g1e2p.capture = PAWN;
   Move g1h3;
   g1h3.source.colRow = 0x60;
   g1h3.dest.colRow = 0x52;
   g1h3.capture = SPACE;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(g1e2p) != moves.end());
   assertUnit(moves.find(g1h3) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   Board board;
   Knight knight(3, 4, false);  // d5, black knight
   knight.fWhite = false;
   knight.position.colRow = 0x34;  // row=3, col=4 encoded as hex?

   board.board[3][4] = &knight;

   Black blackPawn1(PAWN);
   Black blackPawn2(PAWN);
   Black blackPawn3(PAWN);
   Black blackPawn4(PAWN);
   Black blackPawn5(PAWN);
   Black blackPawn6(PAWN);
   Black blackPawn7(PAWN);
   Black blackPawn8(PAWN);

   board.board[1][3] = &blackPawn1;  // c7
   board.board[1][5] = &blackPawn2;  // e7
   board.board[2][2] = &blackPawn3;  // b6
   board.board[2][6] = &blackPawn4;  // f6
   board.board[4][2] = &blackPawn5;  // b4
   board.board[4][6] = &blackPawn6;  // f4
   board.board[5][3] = &blackPawn7;  // c3
   board.board[5][5] = &blackPawn8;  // e3

   std::set<Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);

   // TEARDOWN
   board.board[3][4] = nullptr;
   board.board[1][3] = nullptr;
   board.board[1][5] = nullptr;
   board.board[2][2] = nullptr;
   board.board[2][6] = nullptr;
   board.board[4][2] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][3] = nullptr;
   board.board[5][5] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   // SETUP
   Board board;
   Knight knight(3, 4, false);  // d5, black knight
   knight.fWhite = false;
   knight.position.colRow = 0x34;  // encode row=3, col=4

   board.board[3][4] = &knight;

   // Place white pawns at capture positions (opponent pieces)
   White whitePawn1(PAWN);
   White whitePawn2(PAWN);
   White whitePawn3(PAWN);
   White whitePawn4(PAWN);
   White whitePawn5(PAWN);
   White whitePawn6(PAWN);
   White whitePawn7(PAWN);
   White whitePawn8(PAWN);

   board.board[1][3] = &whitePawn1;  // c7
   board.board[1][5] = &whitePawn2;  // e7
   board.board[2][2] = &whitePawn3;  // b6
   board.board[2][6] = &whitePawn4;  // f6
   board.board[4][2] = &whitePawn5;  // b4
   board.board[4][6] = &whitePawn6;  // f4
   board.board[5][3] = &whitePawn7;  // c3
   board.board[5][5] = &whitePawn8;  // e3

   set<Move> moves;

   // EXPECTED MOVES (captures)
   Move capture1;
   capture1.source.colRow = 0x34;  // knight pos
   capture1.dest.colRow = 0x13;    // c7
   capture1.capture = PAWN;

   Move capture2;
   capture2.source.colRow = 0x34;
   capture2.dest.colRow = 0x15;    // e7
   capture2.capture = PAWN;

   Move capture3;
   capture3.source.colRow = 0x34;
   capture3.dest.colRow = 0x22;    // b6
   capture3.capture = PAWN;

   Move capture4;
   capture4.source.colRow = 0x34;
   capture4.dest.colRow = 0x26;    // f6
   capture4.capture = PAWN;

   Move capture5;
   capture5.source.colRow = 0x34;
   capture5.dest.colRow = 0x42;    // b4
   capture5.capture = PAWN;

   Move capture6;
   capture6.source.colRow = 0x34;
   capture6.dest.colRow = 0x46;    // f4
   capture6.capture = PAWN;

   Move capture7;
   capture7.source.colRow = 0x34;
   capture7.dest.colRow = 0x53;    // c3
   capture7.capture = PAWN;

   Move capture8;
   capture8.source.colRow = 0x34;
   capture8.dest.colRow = 0x55;    // e3
   capture8.capture = PAWN;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);

   assertUnit(moves.find(capture1) != moves.end());
   assertUnit(moves.find(capture2) != moves.end());
   assertUnit(moves.find(capture3) != moves.end());
   assertUnit(moves.find(capture4) != moves.end());
   assertUnit(moves.find(capture5) != moves.end());
   assertUnit(moves.find(capture6) != moves.end());
   assertUnit(moves.find(capture7) != moves.end());
   assertUnit(moves.find(capture8) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr;

   board.board[1][3] = nullptr;
   board.board[1][5] = nullptr;
   board.board[2][2] = nullptr;
   board.board[2][6] = nullptr;
   board.board[4][2] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][3] = nullptr;
   board.board[5][5] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   // SETUP
   BoardEmpty board;  // empty board, all nullptrs

   Knight knight(3, 4, true);  // d5, white knight
   knight.fWhite = true;
   knight.position.colRow = 0x34;  // encode row=3, col=4

   board.board[3][4] = &knight;

   std::set<Move> moves;

   // Expected knight moves (no captures, all SPACE)
   Move move1;
   move1.source.colRow = 0x34;
   move1.dest.colRow = 0x13;  // c7
   move1.capture = SPACE;

   Move move2;
   move2.source.colRow = 0x34;
   move2.dest.colRow = 0x15;  // e7
   move2.capture = SPACE;

   Move move3;
   move3.source.colRow = 0x34;
   move3.dest.colRow = 0x22;  // b6
   move3.capture = SPACE;

   Move move4;
   move4.source.colRow = 0x34;
   move4.dest.colRow = 0x26;  // f6
   move4.capture = SPACE;

   Move move5;
   move5.source.colRow = 0x34;
   move5.dest.colRow = 0x42;  // b4
   move5.capture = SPACE;

   Move move6;
   move6.source.colRow = 0x34;
   move6.dest.colRow = 0x46;  // f4
   move6.capture = SPACE;

   Move move7;
   move7.source.colRow = 0x34;
   move7.dest.colRow = 0x53;  // c3
   move7.capture = SPACE;

   Move move8;
   move8.source.colRow = 0x34;
   move8.dest.colRow = 0x55;  // e3
   move8.capture = SPACE;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);

   assertUnit(moves.find(move1) != moves.end());
   assertUnit(moves.find(move2) != moves.end());
   assertUnit(moves.find(move3) != moves.end());
   assertUnit(moves.find(move4) != moves.end());
   assertUnit(moves.find(move5) != moves.end());
   assertUnit(moves.find(move6) != moves.end());
   assertUnit(moves.find(move7) != moves.end());
   assertUnit(moves.find(move8) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr;
}

/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP  
   const Knight knight(7, 7, false /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = knight.getType();

   // VERIFY
   assertUnit(pt == KNIGHT);
}  // TEARDOWN
