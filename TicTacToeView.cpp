//
//  TicTacToeView.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include "TicTacToeView.h"
#include <iostream>

using namespace std;

void TicTacToeView::PrintBoard(std::ostream &s) const {
   cout << "- 0 1 2";
   
   for ( int i = 0; i < TIC_TAC_TOE_BOARD_SIZE; i++) {
      cout << "\n" << i << " ";
      for( int j = 0; j < TIC_TAC_TOE_BOARD_SIZE; j++) {
         char temp = mTicTacToeBoard->mBoard[i][j];
         if (temp == 0)
            cout << ". ";
         
         else if (temp == 1)
            cout << "X ";
         
         else if (temp == -1)
            cout << "O ";
      }
   }
   cout << endl;
}
