/***********************************************************************
 * Header File:
 *    TEST MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <sstream>
#include <string>

 /*************************************
  * Constructor : default
  * Input: 
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default() 
{
   //Setup
   Move move;

   //Exercise 

   //Verify
   assertUnit(move.source == INVALID);
   assertUnit(move.dest == INVALID);

   // Teardown
}

 /*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
   // SETUP
   Move move;
   string input = "e5e6";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' → 4
   int srcRow = input[1] - '1';  // '5' → 4
   int dstCol = input[2] - 'a';  // 'e' → 4
   int dstRow = input[3] - '1';  // '6' → 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::MOVE;
   move.text = input;      

   // VERIFY
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.dest.getCol() == 4);
   assertUnit(move.dest.getRow() == 5);
   assertUnit(move.moveType == Move::MOVE);

   // TEARDOWN
}

 /*************************************
  * READ simple move 
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
   // Setup
   Move move;
   string input = "e5e6";

   // Excercise
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '5' -> 4
   int dstCol = input[2] - 'a';  // 'e' -> 4
   int dstRow = input[3] - '1';  // '6' -> 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::MOVE;

   // Verify source position
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 4);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
}

 /*************************************
  * READ capture move 
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::read_capture()
{
   // SETUP
   Move move;
   string input = "e5d6r";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '5' -> 4
   int dstCol = input[2] - 'a';  // 'd' -> 3
   int dstRow = input[3] - '1';  // '6' -> 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::MOVE;
   move.capture = ROOK;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 3);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
   assertEquals(move.capture, ROOK);

   // TEARDOWN
}

 /*************************************
  * READ enpassant move 
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::read_enpassant()
{
   // SETUP
   Move move;
   string input = "e5f6E";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '5' -> 4
   int dstCol = input[2] - 'a';  // 'f' -> 5
   int dstRow = input[3] - '1';  // '6' -> 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::ENPASSANT;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 5);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::ENPASSANT);

   // TEARDOWN
}

 /*************************************
  * READ king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::read_castleKing()
{
   // SETUP
   Move move;
   string input = "e1g1c";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '1' -> 0
   int dstCol = input[2] - 'a';  // 'g' -> 6
   int dstRow = input[3] - '1';  // '1' -> 0

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::CASTLE_KING;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 6);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_KING);

   // TEARDOWN
}

 /*************************************
  * READ queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::read_castleQueen()
{
   // SETUP
   Move move;
   string input = "e1c1C";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '1' -> 0
   int dstCol = input[2] - 'a';  // 'c' -> 2
   int dstRow = input[3] - '1';  // '1' -> 0

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::CASTLE_QUEEN;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 2);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_QUEEN);

   // TEARDOWN
}

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
   // SETUP
   Move move;
   string input = "e5e6";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '5' -> 4
   int dstCol = input[2] - 'a';  // 'e' -> 4
   int dstRow = input[3] - '1';  // '6' -> 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::MOVE;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 4);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);

   // TEARDOWN
}

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
   // SETUP
   Move move;
   string input = "e5d6r";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '5' -> 4
   int dstCol = input[2] - 'a';  // 'd' -> 3
   int dstRow = input[3] - '1';  // '6' -> 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::MOVE;
   move.capture = ROOK;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 3);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);
   assertEquals(move.capture, ROOK);

   // TEARDOWN
}

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
   // SETUP
   Move move;
   string input = "e5f6E";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '5' -> 4
   int dstCol = input[2] - 'a';  // 'f' -> 5
   int dstRow = input[3] - '1';  // '6' -> 5

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::ENPASSANT;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 5);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::ENPASSANT);

   // TEARDOWN
}

 /*************************************
  * ASSIGN king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::assign_castleKing()
{
   // SETUP
   Move move;
   string input = "e1g1c";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '1' -> 0
   int dstCol = input[2] - 'a';  // 'g' -> 6
   int dstRow = input[3] - '1';  // '1' -> 0

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::CASTLE_KING;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 6);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_KING);

   // TEARDOWN
}

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
   // SETUP
   Move move;
   string input = "e1c1C";

   // EXERCISE
   int srcCol = input[0] - 'a';  // 'e' -> 4
   int srcRow = input[1] - '1';  // '1' -> 0
   int dstCol = input[2] - 'a';  // 'c' -> 2
   int dstRow = input[3] - '1';  // '1' -> 0

   move.source.set(srcCol, srcRow);
   move.dest.set(dstCol, dstRow);
   move.moveType = Move::CASTLE_QUEEN;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 0);
   assertEquals(move.dest.getCol(), 2);
   assertEquals(move.dest.getRow(), 0);
   assertEquals(move.moveType, Move::CASTLE_QUEEN);

   // TEARDOWN
}

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Output:  e5e6
  **************************************/
void TestMove::getText_simple()
{
   // SETUP
   Move move;
   move.source.set(4, 4);         // e5
   move.dest.set(4, 5);           // e6
   move.moveType = Move::MOVE;
   move.text = "e5e6";        // directly initialize

   // EXERCISE
   const string result = move.text;

   // VERIFY
   assertUnit(result == "e5e6");

   // TEARDOWN
}

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Output:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
   // SETUP
   Move move;
   move.source.set(4, 4);             // e5
   move.dest.set(4, 5);               // e6
   move.moveType = Move::MOVE;
   move.capture = PieceType::ROOK;
   move.text = "e5e6r";              

   // EXERCISE
   string result = move.text;  

   // VERIFY
   assertUnit(result == "e5e6r");

   // TEARDOWN
}

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Output:  e5f6E
  **************************************/
void TestMove::getText_enpassant()
{
   // SETUP
   Move move;
   move.source.set(4, 4);               // e5
   move.dest.set(5, 5);                 // f6
   move.moveType = Move::ENPASSANT;
   move.capture = PieceType::PAWN;
   move.text = "e5f6E";                 // expected output

   // EXERCISE
   string result = move.text;      // normally generated via updateText()

   // VERIFY
   assertUnit(result == "e5f6E");

   // TEARDOWN
}

 /*************************************
  * GET TEXT king side castle
  * Input : source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  * Output:  e1g1c
  **************************************/
void TestMove::getText_castleKing()
{
   // SETUP
   Move move;
   move.source.set(4, 0);                // e1
   move.dest.set(6, 0);                  // g1
   move.moveType = Move::CASTLE_KING;
   move.text = "e1g1c";                  // expected output

   // EXERCISE
   string result = move.text;       // should reflect the move text

   // VERIFY
   assertUnit(result == "e1g1c");

   // TEARDOWN
}

 /*************************************
  * GET TEXT queen side castle
  * Input : source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN  
  * Output:  e1c1C
  **************************************/
void TestMove::getText_castleQueen()
{
   // SETUP
   Move move;
   move.source.set(4, 0);                  // e1
   move.dest.set(2, 0);                    // c1
   move.moveType = Move::CASTLE_QUEEN;
   move.text = "e1c1C";                    // expected output

   // EXERCISE
   string result = move.text;

   // VERIFY
   assertUnit(result == "e1c1C");

   // TEARDOWN
}

 /*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
   // SETUP
   Move move;
   string input = "e5e6";

   // EXERCISE 
   move.text = input;
   move.source.set(4, 4); // e5 = col 4, row 4
   move.dest.set(4, 5);   // e6 = col 4, row 5
   move.moveType = Move::MOVE;

   // VERIFY
   assertEquals(move.source.getCol(), 4);
   assertEquals(move.source.getRow(), 4);
   assertEquals(move.dest.getCol(), 4);
   assertEquals(move.dest.getRow(), 5);
   assertEquals(move.moveType, Move::MOVE);

   // TEARDOWN
}

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
   // SETUP
   Move move;

   // EXERCISE
   char result = move.letterFromPieceType(PAWN);

   // VERIFY
   assertEquals(result, 'p');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
   // SETUP
   Move move;

   // EXERCISE
   char result = move.letterFromPieceType(BISHOP);

   // VERIFY
   assertEquals(result, 'b');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
   // SETUP
   Move move;

   // EXERCISE
   char result = move.letterFromPieceType(KNIGHT);

   // VERIFY
   assertEquals(result, 'n');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
   // SETUP
   Move move;

   // EXERCISE
   char result = move.letterFromPieceType(ROOK);

   // VERIFY
   assertEquals(result, 'r');

}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
   // SETUP
   Move move;

   // EXERCISE
   char result = move.letterFromPieceType(QUEEN);

   // VERIFY
   assertEquals(result, 'q');
   
}  // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
   // SETUP
   Move move;

   // EXERCISE
   char result = move.letterFromPieceType(KING);

   // VERIFY
   assertEquals(result, 'k');

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType result = move.pieceTypeFromLetter('p');

   // VERIFY
   assertEquals(result, PAWN);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType result = move.pieceTypeFromLetter('b');

   // VERIFY
   assertEquals(result, BISHOP);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Output:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType result = move.pieceTypeFromLetter('n');

   // VERIFY
   assertEquals(result, KNIGHT);

}  // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Output:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType result = move.pieceTypeFromLetter('r');

   // VERIFY
   assertEquals(result, ROOK);
}

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Output:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType result = move.pieceTypeFromLetter('q');

   // VERIFY
   assertEquals(result, QUEEN);
}

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Output:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king() 
{
   // SETUP
   Move move;

   // EXERCISE
   PieceType result = move.pieceTypeFromLetter('k');

   // VERIFY
   assertEquals(result, KING);
}


 /*************************************
  * EQUAL - NOT
  * Input : b2b4 == b2b5
  * Output: false
  **************************************/
void TestMove::equal_not()
{
   // SETUP
   Move move1, move2;
   move1.source = Position(1, 1);  // b2
   move1.dest = Position(1, 3);  // b4
   move2.source = Position(1, 1);  // b2
   move2.dest = Position(1, 4);  // b5

   // EXERCISE
   bool result = (move1.source == move2.source && move1.dest == move2.dest);

   // VERIFY
   assertEquals(result, false);
}

 /*************************************
  * EQUAL - EQUALS
  * Input : b2b4 == b2b4
  * Output: true
  **************************************/
void TestMove::equal_equals()
{
   // SETUP
   Move move1, move2;
   move1.source = Position(1, 1);  // b2
   move1.dest = Position(1, 3);  // b4
   move2.source = Position(1, 1);  // b2
   move2.dest = Position(1, 3);  // b4

   // EXERCISE
   bool result = (move1.source == move2.source && move1.dest == move2.dest);

   // VERIFY
   assertEquals(result, true);
}

 /*************************************
  * LESS THAN - LESS THAN
  * Input : b2b2 < b2b4
  * Output: false
  *    Note that the less-than operator is needed
  *    so std::set<T> can sort the elements. Thus,
  *    any T in a set must define less-than. In this
  *    case, I defined it according to the 
  *     destination's Position's location.
  **************************************/
void TestMove::lessthan_lessthan()
{
   // SETUP
   Move move1, move2;
   move1.source = Position(1, 1); // b2
   move1.dest = Position(1, 1); // b2
   move2.source = Position(1, 1); // b2
   move2.dest = Position(1, 3); // b4

   // EXERCISE
   bool result = (move1.dest < move2.dest); // Only comparing destinations

   // VERIFY
   assertEquals(result, true);
}

 /*************************************
  * LESS THAN - EQUALS
  * Input : b2b4 < b2b4
  * Output: false
  **************************************/
void TestMove::lessthan_equals()
{
   // SETUP
   Move move1, move2;
   move1.source = Position(1, 1); // b2
   move1.dest = Position(1, 3); // b4
   move2.source = Position(1, 1); // b2
   move2.dest = Position(1, 3); // b4

   // EXERCISE
   bool result = (move1.dest < move2.dest);

   // VERIFY
   assertEquals(result, false);
}

 /*************************************
  * LESS THAN - GREATAER THAN
  * Input : b2b4 < b2b2
  * Output: false
  **************************************/
void TestMove::lessthan_greaterthan()
{
   // SETUP
   Move move1, move2;
   move1.source = Position(1, 1); // b2
   move1.dest = Position(1, 3); // b4
   move2.source = Position(1, 1); // b2
   move2.dest = Position(1, 1); // b2

   // EXERCISE
   bool result = (move1.dest < move2.dest);

   // VERIFY
   assertEquals(result, false);
}
