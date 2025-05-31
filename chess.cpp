/**********************************************************************
* Source File:
*    Lab 04: Chess
* Author:
*    Natalia Navarrete, Diego Estrada
* Summary:
*    Play the game of chess
************************************************************************/


#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for OGSTREAM
#include "position.h"     // for POSITION
#include "piece.h"        // for PIECE and company
#include "board.h"        // for BOARD
#include "test.h"
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   Board* pBoard = (Board*)p;
   Position posHover = pUI->getHoverPosition();
   Position posSelect = pUI->getSelectPosition();

   // Remember previous valid click and current “picked up” piece
   static Position prevSelect(-1, -1);
   static Position posSource(-1, -1);

   // Process a click when the user has clicked a new valid square:
   if (posSelect.isValid() && posSelect != prevSelect)
   {
      // No piece “picked up” yet. first click = pick up a piece
      if (posSource.isInvalid())
      {
         const Piece& clickedPiece = (*pBoard)[posSelect];
         if (clickedPiece.getType() != SPACE)
         {
            // Store this as our “picked up” piece
            posSource = posSelect;
         }
         // Drop the UI’s selection immediately
         // so next frame posSelect will be invalid
         pUI->clearSelectPosition();
      }
      // CASE 2: We already have posSource to second click = drop or cancel
      else
      {
         // If they clicked the same square again, that means “cancel pickup.”
         if (posSelect == posSource)
         {
            posSource = Position(-1, -1);
         }
         // Otherwise, attempt to move from posSource ? posSelect
         else
         {
            const Piece& sourcePiece = (*pBoard)[posSource];
            // Gather all legal moves for that piece
            set<Move> legalMoves;
            sourcePiece.getMoves(legalMoves, *pBoard);

            bool didMove = false;
            for (const Move& m : legalMoves)
            {
               // Only execute a move if it exactly matches our (source to destination)
               if (m.getSource() == posSource && m.getDest() == posSelect)
               {
                  pBoard->move(m);   // update the board
                  didMove = true;
                  break;
               }
            }

            // Regardless of whether we moved or not, clear out posSource so we start fresh
            posSource = Position(-1, -1);
         }
         // Immediately drop the UI’s select so that posSelect becomes invalid next frame
         pUI->clearSelectPosition();
      }

      // update prevSelect = posSelect so that repeating the same square does not retrigger.
      prevSelect = posSelect;
   }

   pBoard->display(posHover, posSource);
}


/*********************************
 * MAIN - Where it all begins...
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   // run all the unit tests
   testRunner();
   
   // Instantiate the graphics window
   Interface ui("Chess");    

   // Initialize the game class
   ogstream* pgout = new ogstream;
   Board board(pgout);

   // set everything into action
   ui.run(callBack, (void *)(&board));      
   
   // All done.
   delete pgout;
   return 0;
}
