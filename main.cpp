//
//  main.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/1/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include <iostream>
#include "OthelloMove.h"
#include "OthelloBoard.h"
#include "OthelloView.h"
#include "TicTacToeMove.h"
#include "TicTacToeBoard.h"
#include "TicTacToeView.h"
#include "ConnectFourMove.h"
#include "ConnectFourBoard.h"
#include "ConnectFourView.h"
#include <string>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
  
   
   while (true) {
      
      GameBoard *board;
      GameView *v;
      vector<GameMove *> possMoves;
      string choice;
      
      cout << "What game would you like to play?\n1. Othello\n2. Tic Tac Toe" <<
      "\n3. Connect Four\nExit" << endl;
      
      
      getline(cin, choice);
      cin.clear();
      
      if (choice == "1") {
         board = new OthelloBoard;
         v = new OthelloView(dynamic_cast<OthelloBoard *>(board));
         cout << "Beginning Othello..." << endl;
      }
      else if (choice == "2") {
         board = new TicTacToeBoard;
         v = new TicTacToeView(dynamic_cast<TicTacToeBoard *>(board));
         cout << "Beginning Tic Tac Toe..." << endl;
      }
      else if (choice == "3") {
         board = new ConnectFourBoard;
         v = new ConnectFourView(dynamic_cast<ConnectFourBoard *>(board));
         cout << "Beginning Connect Four..." << endl;
      }
      else if (choice == "exit") {
         break;
      }
      else {
         cout << "You couldn't choose from 3 different games, so we're" <<
         " playing Tic Tac Toe." << endl;
         board = new TicTacToeBoard;
         v = new TicTacToeView(dynamic_cast<TicTacToeBoard *>(board));
      }
      
      do {
         
         string command1, command2, userInput;
         
         for (GameMove *move : possMoves) {
            delete move;
         }
         possMoves.clear();
         
         istringstream iss;
         bool isValidMove = false;
         cout << *v << endl;
         
         board->GetPossibleMoves(&possMoves);
         
         cout << "Possible moves for " <<
         board->GetPlayerString(board->GetNextPlayer()) << endl;
         
         for (GameMove *move : possMoves) {
            cout << (string) *move << " ";
         }
         cout << endl;
         
         cout << "Enter a command" << endl;
         
         getline(cin, userInput);
         iss.str(userInput);
         iss >> command1;
         
         if (command1 == "move") {
            
            iss >> command2;
            
            GameMove *m = board->CreateMove();
            
            try {
               
               *m = command2;
               
               for (GameMove *move : possMoves) {
                  if (m->Equals(*move)) {
                     isValidMove = true;
                  }
               }
               
               if (isValidMove){
                  board->ApplyMove(m);
               }
               else {
                  cout << "Not a valid move." << endl;
                  delete m;
                  continue;
               }
            }
            catch (GameException e) {
               cout << e.what() << endl;
               delete m;
            }
            
         }
         else if (command1 == "undo") {
            int times;
            
            iss >> times;
            
            for (int i = times; i > 0; i --) {
               if (board->GetMoveHistory()->size() == 0)
                  break;
               else
                  board->UndoLastMove();
            }
         }
         else if (command1 == "showValue") {
            cout << "Board value: " << board->GetValue() << endl << endl;
         }
         else if (command1 == "showHistory") {
            vector<GameMove *> hist = *board->GetMoveHistory();
            int player = board->GetNextPlayer() * -1;
            
            vector<GameMove *>::reverse_iterator rItr = hist.rbegin();
            
            for (int i = 0; i < hist.size(); i++) {
               cout << ((player == -1) ? board->GetPlayerString(-1) :
                        board->GetPlayerString(1)) << ": " <<
               (string) *(*rItr) << endl;
               
               player = -1 * player;
               rItr++;
            }
         }
         else if (command1 == "quit") {
            break;
         }
         
         
      }while (!board->IsFinished());
      
      cout << *v << endl;
      
      for (GameMove *move : possMoves) {
         delete move;
      }
      possMoves.clear();
      
      if (board->GetValue() > 0) {
         cout << board->GetPlayerString(1) << " wins!" << endl;
      }
      else if (board->GetValue() < 0) {
         cout << board->GetPlayerString(-1) << " wins!" << endl;
      }
      else {
         cout << "It's a tie! :(" << endl;
      }
      
      delete board;
   }
    return 0;
}
