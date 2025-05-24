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
	King king(3, 4, true);            // d5
	board.board[3][4] = &king;

	// Surround with friendly pawns on all 8 adjacent
	White pC6(PAWN); board.board[2][5] = &pC6;
	White pD6(PAWN); board.board[3][5] = &pD6;
	White pE6(PAWN); board.board[4][5] = &pE6;
	White pC5(PAWN); board.board[2][4] = &pC5;
	White pE5(PAWN); board.board[4][4] = &pE5;
	White pC4(PAWN); board.board[2][3] = &pC4;
	White pD4(PAWN); board.board[3][3] = &pD4;
	White pE4(PAWN); board.board[4][3] = &pE4;

	set<Move> moves;

   // EXERCISE
	king.getMoves(moves, board);

   // VERIFY
	assertUnit(moves.empty());

	// TEARDOWN
	board.board[3][4] = nullptr;
	board.board[2][5] = nullptr;
	board.board[3][5] = nullptr;
	board.board[4][5] = nullptr;
	board.board[2][4] = nullptr;
	board.board[4][4] = nullptr;
	board.board[2][3] = nullptr;
	board.board[3][3] = nullptr;
	board.board[4][3] = nullptr;
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
	King king(3, 4, true);            // d5
	board.board[3][4] = &king;

	// Surround with enemy pawns
	Black pC6(PAWN); board.board[2][5] = &pC6;
	Black pD6(PAWN); board.board[3][5] = &pD6;
	Black pE6(PAWN); board.board[4][5] = &pE6;
	Black pC5(PAWN); board.board[2][4] = &pC5;
	Black pE5(PAWN); board.board[4][4] = &pE5;
	Black pC4(PAWN); board.board[2][3] = &pC4;
	Black pD4(PAWN); board.board[3][3] = &pD4;
	Black pE4(PAWN); board.board[4][3] = &pE4;

	set<Move> moves;

   // EXERCISE
	king.getMoves(moves, board);

   // VERIFY
	// should be able to capture all 8
	assertUnit(moves.size() == 8);
	assertUnit(moves.count(Move(Position("d5"), Position("c6"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("d6"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("e6"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("c5"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("e5"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("c4"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("d4"), PAWN, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("e4"), PAWN, Move::MOVE, true)));

	// TEARDOWN
	board.board[3][4] = nullptr;
	board.board[2][5] = nullptr;
	board.board[3][5] = nullptr;
	board.board[4][5] = nullptr;
	board.board[2][4] = nullptr;
	board.board[4][4] = nullptr;
	board.board[2][3] = nullptr;
	board.board[3][3] = nullptr;
	board.board[4][3] = nullptr;
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
	// SETUP
	BoardEmpty board;
	King king(3, 4, true);            // d5
	board.board[3][4] = &king;

	set<Move> moves;
	
   // EXERCISE
	king.getMoves(moves, board);

   // VERIFY
	assertUnit(moves.size() == 8);
	// check each of the 8 squares
	assertUnit(moves.count(Move(Position("d5"), Position("c4"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("d4"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("e4"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("c5"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("e5"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("c6"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("d6"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("d5"), Position("e6"), SPACE, Move::MOVE, true)));

   // TEARDOWN
	board.board[3][4] = nullptr;
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
	// SETUP
	BoardEmpty board;
	King king(0, 0, true);            // a1
	board.board[0][0] = &king;

	set<Move> moves;
	
   // EXERCISE
	king.getMoves(moves, board);

   // VERIFY
	assertUnit(moves.size() == 3);
	assertUnit(moves.count(Move(Position("a1"), Position("a2"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("a1"), Position("b1"), SPACE, Move::MOVE, true)));
	assertUnit(moves.count(Move(Position("a1"), Position("b2"), SPACE, Move::MOVE, true)));

   // TEARDOWN
	board.board[0][0] = nullptr;
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
	// SETUP
	BoardEmpty board;
	// white rooks at a1/h1
	Rook rL(0, 0, true), rR(7, 0, true);
	board.board[0][0] = &rL;
	board.board[7][0] = &rR;
	// white king at e1
	King king(4, 0, true);
	board.board[4][0] = &king;
   // white pawns in front of the king
   White pawn1(PAWN), pawn2(PAWN), pawn3(PAWN);
   board.board[3][1] = &pawn1;  // d2
   board.board[4][1] = &pawn2;  // e2
   board.board[5][1] = &pawn3;  // f2

	set<Move> moves;
	
   // EXERCISE
	king.getMoves(moves, board);

   // VERIFY
	assertUnit(moves.size() == 4);
	// kingside castling to g1
	assertUnit(moves.count(Move(Position("e1"), Position("g1"), SPACE, Move::CASTLE_KING, true)));
	// queenside castling to c1
	assertUnit(moves.count(Move(Position("e1"), Position("c1"), SPACE, Move::CASTLE_QUEEN, true)));

   // TEARDOWN
	board.board[0][0] = nullptr;
	board.board[7][0] = nullptr;
	board.board[4][0] = nullptr;
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
	// SETUP
	BoardEmpty board;

	// black rooks at a8 and h8
	Rook rL(0, 7, false), rR(7, 7, false);
	board.board[0][7] = &rL;
	board.board[7][7] = &rR;

	// black king at e8
	King king(4, 7, false);
	board.board[4][7] = &king;

	// black pawns in front of the king
	Black pawn1(PAWN), pawn2(PAWN), pawn3(PAWN);
	board.board[3][6] = &pawn1;  // d7
	board.board[4][6] = &pawn2;  // e7
	board.board[5][6] = &pawn3;  // f7

	set<Move> moves;

	// EXERCISE
	king.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 4);
	// should include kingside castle (e8-g8) and queenside castle (e8?c8)
	assertUnit(moves.count(Move(
		Position("e8"), Position("g8"),
		SPACE, Move::CASTLE_KING, false)));

	assertUnit(moves.count(Move(
		Position("e8"), Position("c8"),
		SPACE, Move::CASTLE_QUEEN, false)));

	// TEARDOWN
	board.board[0][7] = nullptr;
	board.board[7][7] = nullptr;
	board.board[4][7] = nullptr;
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
	// SETUP
	BoardEmpty board;

	// white rooks at a1/h1
	Rook rL(0, 0, true), rR(7, 0, true);
	board.board[0][0] = &rL;
	board.board[7][0] = &rR;

	// white king at e1, but force it to think it's already moved
	King king(4, 0, true);
	king.nMoves = 1;           // simulate "already moved"
	board.board[4][0] = &king;

	// pawns directly in front block any forward or diagonal moves
	White pawnD2(PAWN), pawnE2(PAWN), pawnF2(PAWN);
	board.board[3][1] = &pawnD2;  // d2
	board.board[4][1] = &pawnE2;  // e2
	board.board[5][1] = &pawnF2;  // f2

	set<Move> moves;

	// EXERCISE
	king.getMoves(moves, board);

	// VERIFY: only d1 and f1 remain, no castling
	assertUnit(moves.size() == 2);
	Move moveD1(Position("e1"), Position("d1"), SPACE, Move::MOVE, true);
	Move moveF1(Position("e1"), Position("f1"), SPACE, Move::MOVE, true);
	assertUnit(moves.find(moveD1) != moves.end());
	assertUnit(moves.find(moveF1) != moves.end());

	// TEARDOWN
	board.board[0][0] = nullptr;
	board.board[7][0] = nullptr;
	board.board[4][0] = nullptr;
	board.board[3][1] = nullptr;
	board.board[4][1] = nullptr;
	board.board[5][1] = nullptr;
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
	// SETUP
	BoardEmpty board;

	// white rooks at a1/h1
	Rook rL(0, 0, true), rR(7, 0, true);
	rL.nMoves = 1;           // simulate "already moved"
	rR.nMoves = 1;           // simulate "already moved"
	board.board[0][0] = &rL;
	board.board[7][0] = &rR;

	// white king at e1, but force it to think it's already moved
	King king(4, 0, true);
	board.board[4][0] = &king;

	// pawns directly in front block any forward or diagonal moves
	White pawnD2(PAWN), pawnE2(PAWN), pawnF2(PAWN);
	board.board[3][1] = &pawnD2;  // d2
	board.board[4][1] = &pawnE2;  // e2
	board.board[5][1] = &pawnF2;  // f2

	set<Move> moves;

	// EXERCISE
	king.getMoves(moves, board);

	// VERIFY: only d1 and f1 remain, no castling
	assertUnit(moves.size() == 2);
	Move moveD1(Position("e1"), Position("d1"), SPACE, Move::MOVE, true);
	Move moveF1(Position("e1"), Position("f1"), SPACE, Move::MOVE, true);
	assertUnit(moves.find(moveD1) != moves.end());
	assertUnit(moves.find(moveF1) != moves.end());

	// TEARDOWN
	board.board[0][0] = nullptr;
	board.board[7][0] = nullptr;
	board.board[4][0] = nullptr;
	board.board[3][1] = nullptr;
	board.board[4][1] = nullptr;
	board.board[5][1] = nullptr;
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
	// SETUP
	King king(4, 0, true); // position doesn't matter here

	// EXERCISE
	PieceType pt = king.getType();

	// VERIFY
	assert(pt == KING);

   // TEARDOWN
}


