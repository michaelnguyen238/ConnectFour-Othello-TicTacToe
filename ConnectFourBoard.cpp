//
//  ConnectFourBoard.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include <stdio.h>
#include "ConnectFourBoard.h"
#include <iostream>

using namespace std;

ConnectFourBoard::ConnectFourBoard() {
   mValue = 0;
   mNextPlayer = ConnectFourBoard::Player::YELLOW;
   FOUR_IN_A_ROW = 0;
   
   for (int r = 0; r < MAX_ROWS; r++) {
      for (int c = 0; c < MAX_COLS; c++) {
         mBoard[r][c] = 0;
      }
   }
}

void ConnectFourBoard::GetPossibleMoves(std::vector<GameMove *> *list) const {
   
   for (int cItr = 0; cItr < MAX_COLS; cItr++) {
      if (mBoard[0][cItr] == 0) {
         list->push_back(new ConnectFourMove(cItr));
      }
   }
}

void ConnectFourBoard::ApplyMove(GameMove *move) {
   ConnectFourMove *m = dynamic_cast<ConnectFourMove *>(move);
   cout << (string) *m << endl;
   
   int row = 0;
   while (mBoard[row+1][m->mCol] == 0 && InBounds(row + 1, m->mCol)) {
      row++;
   }
   mBoard[row][m->mCol] = GetNextPlayer();
   
   int r,c;
   int count = 0;
   
   for (int rowDelta = -1; rowDelta <= 1; rowDelta++) {
      for (int colDelta = -1; colDelta <= 1; colDelta++) {
         r = row + rowDelta;
         c = m->mCol + colDelta;
         //cout << "Looking at " << r << "," << c << endl;
         while (InBounds(r, c) && mBoard[r][c] == GetNextPlayer() &&
                !FOUR_IN_A_ROW && !(rowDelta == 0 && colDelta == 0)) {
            r += rowDelta;
            c += colDelta;
            //cout << "Traversing to " << r << "," << c << endl;
            count++;
            //cout << "Count: " << count << endl;
            if (count == 4)
               FOUR_IN_A_ROW = true;
         }
         
         r = row;
         c = m->mCol;
         //cout << "Looking at " << r << "," << c << endl;
         while (InBounds(r - rowDelta, c - colDelta) && mBoard[r][c] == GetNextPlayer() &&
                !FOUR_IN_A_ROW && !(rowDelta == 0 && colDelta == 0)) {
            r -= rowDelta;
            c -= colDelta;
            // cout << "Traversing to " << r << "," << c << endl;
            count++;
            //cout << "Count: " << count << endl;
            if (count == 4)
               FOUR_IN_A_ROW = true;
         }
         
         
         if (!FOUR_IN_A_ROW)
            count = 0;
      }
      if (FOUR_IN_A_ROW)
         mValue = GetNextPlayer();
   }
   
   
   mNextPlayer = GetNextPlayer() * -1;
   mHistory.push_back(m);
}

void ConnectFourBoard::UndoLastMove() {
   ConnectFourMove *m = dynamic_cast<ConnectFourMove *>(mHistory.back());
   
   int row = 0;
   while (mBoard[row][m->mCol] == 0) {
      row++;
   }
   
   mBoard[row][m->mCol] = 0;
   
   mNextPlayer = GetNextPlayer() * -1;
   delete mHistory.back();
   mHistory.pop_back();
}
