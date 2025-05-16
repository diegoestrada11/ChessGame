/***********************************************************************
 * Header File:
 *    TEST BOARD
 * Author:
 *    Natalia Navarrete, Diego Estrada
 * Summary:
 *    The unit tests for Board
 ************************************************************************/

#pragma once

#include "unitTest.h"

class Board;

/***************************************************
 * BOARD TEST
 * Test the Board class
 ***************************************************/
class TestBoard : public UnitTest
{
public:
   void run()
   {
      // move
      move_knightMove();
      move_knightAttack();
      report("Board");
   }
private:

   void move_knightMove();
   void move_knightAttack();
};

