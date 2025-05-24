/***********************************************************************
 * Source File:
 *    TEST BOARD
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for board
 ************************************************************************/


#include "testBoard.h"
#include "board.h"
#include "position.h"
#include "piece.h"
#include "piecePawn.h"
#include "pieceRook.h"
#include "pieceBishop.h"
#include "pieceQueen.h"
#include "pieceKnight.h"
#include "pieceKing.h"
#include <cassert>


 /***********************************************
  * CREATE DUMMY BOARD : Constructor for DummyBoard
  * Setup:
  * VERIFY: all squares have the null pointer
  ***********************************************/
void TestBoard::construct_dummyBoard()
{
   // SETUP

   // EXERCISE
   BoardDummy board;

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(nullptr == board.board[0][0]);
   assertUnit(nullptr == board.board[1][0]);
   assertUnit(nullptr == board.board[2][0]);
   assertUnit(nullptr == board.board[3][0]);
   assertUnit(nullptr == board.board[4][0]);
   assertUnit(nullptr == board.board[5][0]);
   assertUnit(nullptr == board.board[6][0]);
   assertUnit(nullptr == board.board[7][0]);
   assertUnit(nullptr == board.board[0][1]);
   assertUnit(nullptr == board.board[1][1]);
   assertUnit(nullptr == board.board[2][1]);
   assertUnit(nullptr == board.board[3][1]);
   assertUnit(nullptr == board.board[4][1]);
   assertUnit(nullptr == board.board[5][1]);
   assertUnit(nullptr == board.board[6][1]);
   assertUnit(nullptr == board.board[7][1]);
   assertUnit(nullptr == board.board[0][2]);
   assertUnit(nullptr == board.board[1][2]);
   assertUnit(nullptr == board.board[2][2]);
   assertUnit(nullptr == board.board[3][2]);
   assertUnit(nullptr == board.board[4][2]);
   assertUnit(nullptr == board.board[5][2]);
   assertUnit(nullptr == board.board[6][2]);
   assertUnit(nullptr == board.board[7][2]);
   assertUnit(nullptr == board.board[0][3]);
   assertUnit(nullptr == board.board[1][3]);
   assertUnit(nullptr == board.board[2][3]);
   assertUnit(nullptr == board.board[3][3]);
   assertUnit(nullptr == board.board[4][3]);
   assertUnit(nullptr == board.board[5][3]);
   assertUnit(nullptr == board.board[6][3]);
   assertUnit(nullptr == board.board[7][3]);
   assertUnit(nullptr == board.board[0][4]);
   assertUnit(nullptr == board.board[1][4]);
   assertUnit(nullptr == board.board[2][4]);
   assertUnit(nullptr == board.board[3][4]);
   assertUnit(nullptr == board.board[4][4]);
   assertUnit(nullptr == board.board[5][4]);
   assertUnit(nullptr == board.board[6][4]);
   assertUnit(nullptr == board.board[7][4]);
   assertUnit(nullptr == board.board[0][5]);
   assertUnit(nullptr == board.board[1][5]);
   assertUnit(nullptr == board.board[2][5]);
   assertUnit(nullptr == board.board[3][5]);
   assertUnit(nullptr == board.board[4][5]);
   assertUnit(nullptr == board.board[5][5]);
   assertUnit(nullptr == board.board[6][5]);
   assertUnit(nullptr == board.board[7][5]);
   assertUnit(nullptr == board.board[0][6]);
   assertUnit(nullptr == board.board[1][6]);
   assertUnit(nullptr == board.board[2][6]);
   assertUnit(nullptr == board.board[3][6]);
   assertUnit(nullptr == board.board[4][6]);
   assertUnit(nullptr == board.board[5][6]);
   assertUnit(nullptr == board.board[6][6]);
   assertUnit(nullptr == board.board[7][6]);
   assertUnit(nullptr == board.board[0][7]);
   assertUnit(nullptr == board.board[1][7]);
   assertUnit(nullptr == board.board[2][7]);
   assertUnit(nullptr == board.board[3][7]);
   assertUnit(nullptr == board.board[4][7]);
   assertUnit(nullptr == board.board[5][7]);
   assertUnit(nullptr == board.board[6][7]);
   assertUnit(nullptr == board.board[7][7]);

}  // TEARDOWN

 /***********************************************
  * CREATE EMPTY BOARD : Constructor for BoardEmpty
  * Setup:
  * VERIFY: all squares have the null pointer
  ***********************************************/
void TestBoard::construct_emptyBoard()
{
   // SETUP

   // EXERCISE
   BoardEmpty board;

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(nullptr == board.board[0][0]);
   assertUnit(nullptr == board.board[1][0]);
   assertUnit(nullptr == board.board[2][0]);
   assertUnit(nullptr == board.board[3][0]);
   assertUnit(nullptr == board.board[4][0]);
   assertUnit(nullptr == board.board[5][0]);
   assertUnit(nullptr == board.board[6][0]);
   assertUnit(nullptr == board.board[7][0]);
   assertUnit(nullptr == board.board[0][1]);
   assertUnit(nullptr == board.board[1][1]);
   assertUnit(nullptr == board.board[2][1]);
   assertUnit(nullptr == board.board[3][1]);
   assertUnit(nullptr == board.board[4][1]);
   assertUnit(nullptr == board.board[5][1]);
   assertUnit(nullptr == board.board[6][1]);
   assertUnit(nullptr == board.board[7][1]);
   assertUnit(nullptr == board.board[0][2]);
   assertUnit(nullptr == board.board[1][2]);
   assertUnit(nullptr == board.board[2][2]);
   assertUnit(nullptr == board.board[3][2]);
   assertUnit(nullptr == board.board[4][2]);
   assertUnit(nullptr == board.board[5][2]);
   assertUnit(nullptr == board.board[6][2]);
   assertUnit(nullptr == board.board[7][2]);
   assertUnit(nullptr == board.board[0][3]);
   assertUnit(nullptr == board.board[1][3]);
   assertUnit(nullptr == board.board[2][3]);
   assertUnit(nullptr == board.board[3][3]);
   assertUnit(nullptr == board.board[4][3]);
   assertUnit(nullptr == board.board[5][3]);
   assertUnit(nullptr == board.board[6][3]);
   assertUnit(nullptr == board.board[7][3]);
   assertUnit(nullptr == board.board[0][4]);
   assertUnit(nullptr == board.board[1][4]);
   assertUnit(nullptr == board.board[2][4]);
   assertUnit(nullptr == board.board[3][4]);
   assertUnit(nullptr == board.board[4][4]);
   assertUnit(nullptr == board.board[5][4]);
   assertUnit(nullptr == board.board[6][4]);
   assertUnit(nullptr == board.board[7][4]);
   assertUnit(nullptr == board.board[0][5]);
   assertUnit(nullptr == board.board[1][5]);
   assertUnit(nullptr == board.board[2][5]);
   assertUnit(nullptr == board.board[3][5]);
   assertUnit(nullptr == board.board[4][5]);
   assertUnit(nullptr == board.board[5][5]);
   assertUnit(nullptr == board.board[6][5]);
   assertUnit(nullptr == board.board[7][5]);
   assertUnit(nullptr == board.board[0][6]);
   assertUnit(nullptr == board.board[1][6]);
   assertUnit(nullptr == board.board[2][6]);
   assertUnit(nullptr == board.board[3][6]);
   assertUnit(nullptr == board.board[4][6]);
   assertUnit(nullptr == board.board[5][6]);
   assertUnit(nullptr == board.board[6][6]);
   assertUnit(nullptr == board.board[7][6]);
   assertUnit(nullptr == board.board[0][7]);
   assertUnit(nullptr == board.board[1][7]);
   assertUnit(nullptr == board.board[2][7]);
   assertUnit(nullptr == board.board[3][7]);
   assertUnit(nullptr == board.board[4][7]);
   assertUnit(nullptr == board.board[5][7]);
   assertUnit(nullptr == board.board[6][7]);
   assertUnit(nullptr == board.board[7][7]);

}  // TEARDOWN


/***********************************************
 * GET CURRENT MOVE : initially the board is empty
 * Setup:  board.numMoves=0
 * VERIFY: moveNumber=0
 ***********************************************/
void TestBoard::getCurrentMove_initial()

{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 0;
   int moveNumber = -1;

   // EXERCISE
   moveNumber = board.getCurrentMove();

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(moveNumber == 0);

}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : second move
 * Setup:  board.numMoves=1
 * VERIFY: moveNumber=1
 ***********************************************/
void TestBoard::getCurrentMove_second()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 1;
   int moveNumber = -1;

   // EXERCISE
   moveNumber = board.getCurrentMove();

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(moveNumber == 1);

}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : white turn in the middle of the game
 * Setup:  board.numMoves=4
 * VERIFY: moveNumber=4
 ***********************************************/
void TestBoard::getCurrentMove_middleWhite()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 4;
   int moveNumber = -1;

   // EXERCISE
   moveNumber = board.getCurrentMove();

   // VERIFY
   assertUnit(4 == board.numMoves);
   assertUnit(moveNumber == 4);

}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : black turn in the middle of the game
 * Setup:  board.numMoves=5
 * VERIFY: moveNumber=5
 ***********************************************/
void TestBoard::getCurrentMove_middleBlack()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 5;
   int moveNumber = -1;

   // EXERCISE
   moveNumber = board.getCurrentMove();

   // VERIFY
   assertUnit(5 == board.numMoves);
   assertUnit(moveNumber == 5);

}  // TEARDOWN

/***********************************************
 * WHITE TURN : initially the board is empty
 * Setup:  board.numMoves=0
 * VERIFY: isWhiteTurn=true
 ***********************************************/
void TestBoard::whiteTurn_initial()
{
   // SETUP
   Board board;
   board.numMoves = 0;
   createDummyBoard(board);
   bool isWhiteTurn;

   // EXERCISE
   isWhiteTurn = board.whiteTurn();

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(isWhiteTurn == true);

}  // TEARDOWN

/***********************************************
 * WHITE TURN : second move
 * Setup:  board.numMoves=1
 * VERIFY: isWhiteTurn=false
 ***********************************************/
void TestBoard::whiteTurn_second()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 1;
   bool isWhiteTurn;

   // EXERCISE
   isWhiteTurn = board.whiteTurn();

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(isWhiteTurn == false);

}  // TEARDOWN

/***********************************************
 * WHITE TURN : white turn in the middle of the game
 * Setup:  board.numMoves=4
 * VERIFY: isWhiteTurn=true
 ***********************************************/
void TestBoard::whiteTurn_middleWhite()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 4;
   bool isWhiteTurn;

   // EXERCISE
   isWhiteTurn = board.whiteTurn();

   // VERIFY
   assertUnit(4 == board.numMoves);
   assertUnit(isWhiteTurn == true);

}  // TEARDOWN

/***********************************************
 * WHITE TURN : black turn in the middle of the game
 * Setup:  board.numMoves=5
 * VERIFY: isWhiteTurn=false
 ***********************************************/
void TestBoard::whiteTurn_middleBlack()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 5;
   bool isWhiteTurn;

   // EXERCISE
   isWhiteTurn = board.whiteTurn();

   // VERIFY
   assertUnit(5 == board.numMoves);
   assertUnit(isWhiteTurn == false);

}  // TEARDOWN

class Position00 : public Position
{
public:
   int getRow() const { return 0; }
   int getCol() const { return 0; }
};

/***********************************************
 * FETCH : a1
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1  (x)                1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_a1()
{
   // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[0][0];
   board.board[0][0] = &piece;
   Position00 pos;
   Piece* p = nullptr;

   // exercise
   p = &(board[pos]);

   // verify
   assertUnit(p == &piece);

   // teardown 
   board.board[0][0] = pSave;
}

void TestBoard::set_a1()
{
   // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[0][0];
   board.board[0][0] = &piece;
   Position00 pos;
   Piece* p = nullptr;

   // exercise
   board[pos].fWhite = false;

   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[0][0]->fWhite == false);

   // teardown 
   board.board[0][0] = pSave;
}

class Position77 : public Position
{
public:
   int getRow() const { return 7; }
   int getCol() const { return 7; }
};

/***********************************************
 * FETCH : h8
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                (x)  8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_h8()
{
   // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[7][7];
   board.board[7][7] = &piece;
   Position77 pos;
   Piece* p = nullptr;

   // exercise
   p = &(board[pos]);

   // verify
   assertUnit(p == &piece);

   // teardown 
   board.board[7][7] = pSave;
}

void TestBoard::set_h8()
{
   // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[7][7];
   board.board[7][7] = &piece;
   Position77 pos;
   Piece* p = nullptr;

   // exercise
   board[pos].fWhite = false;

   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[7][7]->fWhite == false);

   // teardown 
   board.board[7][7] = pSave;
}

class Position07 : public Position
{
public:
   int getRow() const { return 7; }
   int getCol() const { return 0; }
};

/***********************************************
 * FETCH : a8
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8  (x)                8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_a8()
{
   // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[0][7];
   board.board[0][7] = &piece;
   Position07 pos;
   Piece* p = nullptr;

   // exercise
   p = &(board[pos]);

   // verify
   assertUnit(p == &piece);

   // teardown 
   board.board[0][7] = pSave;
}

void TestBoard::set_a8()
{
   // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[0][7];
   board.board[0][7] = &piece;
   Position07 pos;
   Piece* p = nullptr;

   // exercise
   board[pos].fWhite = false;

   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[0][7]->fWhite == false);

   // teardown 
   board.board[0][7] = pSave;
}


/***********************************************
 * CREATE DUMMY BOARD
 * Utility function - not a unit test
 * Just fill the board with the known pieces
 ***********************************************/
void TestBoard::createDummyBoard(Board& board)
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
      {
         board.board[c][r] = new PieceDummy;
      }
}

 /********************************************************
  *   a2a3
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3   .                 3       3   p                 3
  * 2  (p)                2       2   .                 2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnSimple()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // place a white pawn on a2 (col=0,row=1)
   board.board[0][1] = new Pawn(0, 1, true);

   // EXERCISE:
   board.move(Move(Position("a2"), Position("a3"), SPACE, Move::MOVE, true));

   // VERIFY
   // pawn should now be at a3
   assertUnit(board.board[0][2]->getType() == PAWN);
   assertUnit(board.board[0][2]->isWhite() == true);
   // a2 should now be a Space
   assertUnit(board.board[0][1]->getType() == SPACE);

   // TEARDOWN
   delete board.board[0][2]; // pawn moved here
   delete board.board[0][1]; // space
}


 /********************************************************
  *     a6b7r
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7     R               7       7    (p)              7
  * 6  (p)                6       6   .                 6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnCapture()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a white pawn on a6
   board.board[0][5] = new Pawn(0, 5, true);
   // put a black rook on b7
   board.board[1][6] = new PieceSpy(1, 6, false, ROOK);

   // EXERCISE
   board.move(Move(Position("a6"), Position("b7"), ROOK, Move::MOVE, true));

   // VERIFY
   // the pawn should now be sitting at b7:
   assertUnit(board.board[1][6]->getType() == PAWN);
   assertUnit(board.board[1][6]->isWhite() == true);
   // and a6 should now be a Space
   assertUnit(board.board[0][5]->getType() == SPACE);

   // TEARDOWN
   delete board.board[1][6];
   delete board.board[0][5];
}


 /********************************************************
  *    e2e4
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4           .         4  -->  4          (p)        4
  * 3                     3       3                     3
  * 2          (p)        2       2           .         2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnDouble()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // white pawn on e2
   board.board[4][1] = new Pawn(4, 1, true);

   // EXERCISE
   board.move(Move(Position("e2"), Position("e4"), SPACE, Move::MOVE, true));

   // VERIFY
   assertUnit(board.board[4][3]->getType() == PAWN);
   assertUnit(board.board[4][3]->isWhite());
   assertUnit(board.board[4][1]->getType() == SPACE);

   // TEARDOWN
   delete board.board[4][3];
   delete board.board[4][1];
}


 /********************************************************
 *     a5b6E
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6     .               6       6     p               6
  * 5  (p)P               5       5   . .               5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnEnpassant()
{
   /// SETUP
   BoardEmpty board;                 // <<-- use BoardEmpty here
   Pawn whiteB5(1, 4, true);         // b5
   board.board[1][4] = &whiteB5;

   Pawn blackC5(2, 4, false);  board.board[2][4] = &blackC5;
   Pawn blackA5(0, 4, false);  board.board[0][4] = &blackA5;
   Pawn blockerB6(1, 5, true); board.board[1][5] = &blockerB6;

   // only c5 just moved two steps
   board.setCurrentMove(1);
   blackC5.setLastMove(board.getCurrentMove());

   // now white to move
   board.setCurrentMove(2);

   // EXERCISE
   set<Move> moves;
   whiteB5.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   Move ep(Position("b5"), Position("c6"), PAWN, Move::ENPASSANT, true);
   assertUnit(moves.count(ep) == 1);


   // TEARDOWN
   board.board[1][4] = nullptr;
   board.board[2][4] = nullptr;
   board.board[0][4] = nullptr;
   board.board[1][5] = nullptr;
}


 /********************************************************
  *    a7a8Q 
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8   .                 8       8  (r)                8
  * 7  (p)                7       7   .                 7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnPromotion()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // white pawn on a7
   board.board[0][6] = new Pawn(0, 6, true);

   // EXERCISE
   Move m(Position("a7"), Position("a8"), SPACE, Move::MOVE, true);
   m.setPromote(QUEEN);
   board.move(m);

   // VERIFY
   assertUnit(board.board[0][7]->getType() == QUEEN);
   assertUnit(board.board[0][7]->isWhite());
   assertUnit(board.board[0][6]->getType() == SPACE);

   // TEARDOWN
   delete board.board[0][7];
   delete board.board[0][6];
}

 /********************************************************
  *    e5a5
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5   .      (r)        5       5  (r)      .         5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_rookSlide()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a white rook on e5
   board.board[4][4] = new Rook(4, 4, true);

   // EXERCISE
   board.move(Move(Position("e5"), Position("a5"), SPACE, Move::MOVE, true));

   // VERIFY
   // the rook should now be at a5:
   assertUnit(board.board[0][4]->getType() == ROOK);
   assertUnit(board.board[0][4]->isWhite() == true);
   // and e5 should now be a Space
   assertUnit(board.board[4][4]->getType() == SPACE);

   // TEARDOWN
   delete board.board[0][4];
   delete board.board[4][4];
}


 /********************************************************
  *    e5a5b
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5   B      (r)        5       5  (r)      .         5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_rookAttack()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a black bishop on a5 to be captured
   board.board[0][4] = new PieceSpy(0, 4, false, BISHOP);
   // put a white rook on e5
   board.board[4][4] = new Rook(4, 4, true);

   // EXERCISE
   board.move(Move(Position("e5"), Position("a5"), BISHOP, Move::MOVE, true));

   // VERIFY
   // the rook should now be at a5:
   assertUnit(board.board[0][4]->getType() == ROOK);
   assertUnit(board.board[0][4]->isWhite() == true);
   // and e5 should now be a Space
   assertUnit(board.board[4][4]->getType() == SPACE);

   // TEARDOWN
   delete board.board[0][4];
   delete board.board[4][4];
}

 /********************************************************
  *    e5g3
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5          (b)        5       5           .         5
  * 4                     4  -->  4                     4
  * 3               .     3       3               b     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_bishopSlide()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a white bishop on e5
   board.board[4][4] = new Bishop(4, 4, true);

   // EXERCISE
   board.move(Move(Position("e5"), Position("g3"), SPACE, Move::MOVE, true));

   // VERIFY
   // the bishop should now be at g3:
   assertUnit(board.board[6][2]->getType() == BISHOP);
   assertUnit(board.board[6][2]->isWhite() == true);
   // and e5 should now be a Space
   assertUnit(board.board[4][4]->getType() == SPACE);

   // TEARDOWN
   delete board.board[6][2];
   delete board.board[4][4];
}


 /********************************************************
  *    e5g3q
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5          (b)        5       5           .         5
  * 4                     4  -->  4                     4
  * 3               Q     3       3               b     3
  * 2                     2       2                     2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_bishopAttack()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a white bishop on e5
   board.board[4][4] = new Bishop(4, 4, true);
   // put a black pawn on g3
   board.board[6][2] = new PieceSpy(6, 2, false, PAWN);

   // EXERCISE
   board.move(Move(Position("e5"), Position("g3"), PAWN, Move::MOVE, true));

   // VERIFY
   // the bishop should now be at g3:
   assertUnit(board.board[6][2]->getType() == BISHOP);
   assertUnit(board.board[6][2]->isWhite() == true);
   // and e5 should now be a Space
   assertUnit(board.board[4][4]->getType() == SPACE);

   // TEARDOWN
   delete board.board[6][2];
   delete board.board[4][4];
}

/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (q)        5       5                     5
 * 4                     4  -->  4           .         4
 * 3                .    3       3               q     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_queenSlide()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a white queen on e5
   board.board[4][4] = new Queen(4, 4, true);

   // EXERCISE
   board.move(Move(Position("e5"), Position("g3"), SPACE, Move::MOVE, true));

   // VERIFY
   // the queen should now be at g3:
   assertUnit(board.board[6][2]->getType() == QUEEN);
   assertUnit(board.board[6][2]->isWhite() == true);
   // and e5 should now be a Space
   assertUnit(board.board[4][4]->getType() == SPACE);

   // TEARDOWN
   delete board.board[6][2];
   delete board.board[4][4];
}


/********************************************************
*    e5a5b
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
* |                     |       |                     |
* 8                     8       8                     8
* 7                     7       7                     7
* 6                     6       6                     6
* 5   B      (q)        5       5  (q)      .         5
* 4                     4  -->  4                     4
* 3                     3       3                     3
* 2                     2       2                     2
* 1                     1       1                     1
* |                     |       |                     |
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
********************************************************/
void TestBoard::move_queenAttack()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // put a white queen on e5
   board.board[4][4] = new Queen(4, 4, true);
   // put a black bishop on b5
   board.board[1][4] = new PieceSpy(1, 4, false, BISHOP);

   // EXERCISE
   board.move(Move(Position("e5"), Position("a5"), BISHOP, Move::MOVE, true));

   // VERIFY
   // the queen should now be at a5:
   assertUnit(board.board[0][4]->getType() == QUEEN);
   assertUnit(board.board[0][4]->isWhite() == true);
   // and e5 should now be a Space
   assertUnit(board.board[4][4]->getType() == SPACE);

   // TEARDOWN
   delete board.board[0][4];
   delete board.board[4][4];
}


 /********************************************************
  *  e1f1
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1          (k).       1       1           . k       1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_kingMove()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   // place white king on e1
   board.board[4][0] = new King(4, 0, true);

   // EXERCISE
   board.move(Move(Position("e1"), Position("f1"), SPACE, Move::MOVE, true));

   // VERIFY
   assertUnit(board.board[5][0]->getType() == KING);
   assertUnit(board.board[5][0]->isWhite());
   assertUnit(board.board[4][0]->getType() == SPACE);

   // TEARDOWN
   delete board.board[5][0];
   delete board.board[4][0];
}


 /********************************************************
  *    e1f1r
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1          (k)R       1       1           . k       1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_kingAttack()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   // place white king on e1 and black rook on f1
   board.board[4][0] = new King(4, 0, true);
   board.board[5][0] = new PieceSpy(5, 0, false, ROOK);

   // EXERCISE
   board.move(Move(Position("e1"), Position("f1"), ROOK, Move::MOVE, true));

   // VERIFY
   assertUnit(board.board[5][0]->getType() == KING);
   assertUnit(board.board[5][0]->isWhite());
   assertUnit(board.board[4][0]->getType() == SPACE);

   // TEARDOWN
   delete board.board[5][0];
   delete board.board[4][0];
}

 /********************************************************
  *    e1g1c
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1          (k). . r   1       1           . r k .   1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_kingShortCastle()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   // place white king on e1 and rook on h1
   board.board[4][0] = new King(4, 0, true);
   board.board[7][0] = new Rook(7, 0, true);

   // EXERCISE
   board.move(Move(Position("e1"), Position("g1"), SPACE, Move::CASTLE_KING, true));

   // VERIFY
   assertUnit(board.board[6][0]->getType() == KING);
   assertUnit(board.board[6][0]->isWhite());
   assertUnit(board.board[5][0]->getType() == ROOK);
   assertUnit(board.board[5][0]->isWhite());
   assertUnit(board.board[4][0]->getType() == SPACE);
   assertUnit(board.board[7][0]->getType() == SPACE);

   // TEARDOWN
   delete board.board[6][0];
   delete board.board[5][0];
   delete board.board[4][0];
   delete board.board[7][0];
}



 /********************************************************
  *    e1c1C 
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3                     3       3                     3
  * 2                     2       2                     2
  * 1   r . . .(k)        1       1   . . k r .         1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_kingLongCastle()
{
   // SETUP
   Board board;
   createDummyBoard(board);
   // place white king on e1 and rook on a1
   board.board[4][0] = new King(4, 0, true);
   board.board[0][0] = new Rook(0, 0, true);

   // EXERCISE
   board.move(Move(Position("e1"), Position("c1"), SPACE, Move::CASTLE_QUEEN, true));

   // VERIFY
   assertUnit(board.board[2][0]->getType() == KING);
   assertUnit(board.board[2][0]->isWhite());
   assertUnit(board.board[3][0]->getType() == ROOK);
   assertUnit(board.board[3][0]->isWhite());
   assertUnit(board.board[4][0]->getType() == SPACE);
   assertUnit(board.board[0][0]->getType() == SPACE);

   // TEARDOWN
   delete board.board[2][0];
   delete board.board[3][0];
   delete board.board[4][0];
   delete board.board[0][0];
}

/******************************************************** 
 *        +---a-b-c-d-e-f-g-h---+
 *        |                     |
 *        8   R N B Q K B N R   8
 *        7   P P P P P P P P   7
 *        6                     6
 *        5                     5
 *   -->  4                     4
 *        3                     3
 *        2   p p p p p p p p   2
 *        1   r n b q k b n r   1
 *        |                     |
 *        +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::construct_default()
{
   // SETUP / EXERCISE
   Board board;   // calls reset()

   // VERIFY
   assertUnit(board.numMoves == 0);

   // White back rank (row 0)
   assertUnit(board.board[0][0]->getType() == ROOK && board.board[0][0]->isWhite());
   assertUnit(board.board[1][0]->getType() == KNIGHT && board.board[1][0]->isWhite());
   assertUnit(board.board[2][0]->getType() == BISHOP && board.board[2][0]->isWhite());
   assertUnit(board.board[3][0]->getType() == QUEEN && board.board[3][0]->isWhite());
   assertUnit(board.board[4][0]->getType() == KING && board.board[4][0]->isWhite());
   assertUnit(board.board[5][0]->getType() == BISHOP && board.board[5][0]->isWhite());
   assertUnit(board.board[6][0]->getType() == KNIGHT && board.board[6][0]->isWhite());
   assertUnit(board.board[7][0]->getType() == ROOK && board.board[7][0]->isWhite());

   // White pawn rank (row 1)
   for (int c = 0; c < 8; ++c)
      assertUnit(board.board[c][1]->getType() == PAWN && board.board[c][1]->isWhite());

   // Empty middle ranks (rows 2–5)
   for (int r = 2; r <= 5; ++r)
      for (int c = 0; c < 8; ++c)
         assertUnit(board.board[c][r] == nullptr);

   // Black pawn rank (row 6)
   for (int c = 0; c < 8; ++c)
      assertUnit(board.board[c][6]->getType() == PAWN && !board.board[c][6]->isWhite());

   // Black back rank (row 7)
   assertUnit(board.board[0][7]->getType() == ROOK && !board.board[0][7]->isWhite());
   assertUnit(board.board[1][7]->getType() == KNIGHT && !board.board[1][7]->isWhite());
   assertUnit(board.board[2][7]->getType() == BISHOP && !board.board[2][7]->isWhite());
   assertUnit(board.board[3][7]->getType() == QUEEN && !board.board[3][7]->isWhite());
   assertUnit(board.board[4][7]->getType() == KING && !board.board[4][7]->isWhite());
   assertUnit(board.board[5][7]->getType() == BISHOP && !board.board[5][7]->isWhite());
   assertUnit(board.board[6][7]->getType() == KNIGHT && !board.board[6][7]->isWhite());
   assertUnit(board.board[7][7]->getType() == ROOK && !board.board[7][7]->isWhite());
} // TEARDOWN


/********************************************************
*  Knight SIMPLE MOVE
*  White knight on e5 -> move to d7 (empty)
********************************************************/
void TestBoard::move_knightMove()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // place a white knight at e5
   delete board.board[4][4];
   board.board[4][4] = new Knight(4, 4, true);

   // EXERCISE
   // perform the move e5 to d7
   Move m(Position("e5"), Position("d7"), SPACE, Move::MOVE, true);
   board.move(m);

   // VERIFY
   // knight should now be at d7 (3,6)
   Piece* pDest = board.board[3][6];

   assertUnit(pDest != nullptr);
   assertUnit(pDest->getType() == KNIGHT);
   assertUnit(pDest->isWhite());

   // source e5 should now be a Space
   Piece* pSrc = board.board[4][4];
   assertUnit(pSrc != nullptr);
   assertUnit(pSrc->getType() == SPACE);

   // move counter incremented
   assertUnit(board.numMoves == 1);

   // TEARDOWN
   delete board.board[3][6];
   delete board.board[4][4];
}

/********************************************************
*  Knight CAPTURE
*  White knight on e5 captures a black pawn on d7
********************************************************/

void TestBoard::move_knightAttack()
{
   // SETUP
   Board board;
   createDummyBoard(board);

   // place a white knight at e5
   delete board.board[4][4];
   board.board[4][4] = new Knight(4, 4, true);

   // place a black pawn at d7
   delete board.board[3][6];
   board.board[3][6] = new PieceSpy(3, 6, false, PAWN);

   // EXERCISE
   // perform the capture e5 to d7
   Move m(Position("e5"), Position("d7"), PAWN, Move::MOVE, true);
   board.move(m);

   // VERIFY
   // knight should be at d7
   Piece* pDest = board.board[3][6];
   assertUnit(pDest != nullptr);
   assertUnit(pDest->getType() == KNIGHT);
   assertUnit(pDest->isWhite());

   // original e5 should now be a Space
   Piece* pSrc = board.board[4][4];
   assertUnit(pSrc != nullptr);
   assertUnit(pSrc->getType() == SPACE);

   // move counter incremented
   assertUnit(board.numMoves == 1);

   // TEARDOWN
   delete board.board[3][6];
   delete board.board[4][4];
}

