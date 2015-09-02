//
//  TicTacToeBoard.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/1/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include <stdio.h>
#include "TicTacToeBoard.h"
#include <iostream>

using namespace std;

TicTacToeBoard::TicTacToeBoard() {
   mValue = 0;
   mNextPlayer = TicTacToeBoard::Player::X;
   THREE_IN_A_ROW = 0;
   
   for (int i = 0; i < TIC_TAC_TOE_BOARD_SIZE; i++) {
      for (int j = 0; j < TIC_TAC_TOE_BOARD_SIZE; j++) {
         mBoard[i][j] = 0;
      }
   }
}

void TicTacToeBoard::GetPossibleMoves(std::vector<GameMove *> *list) const {
   for (int i = 0; i < TIC_TAC_TOE_BOARD_SIZE; i++) {
      for (int j = 0; j < TIC_TAC_TOE_BOARD_SIZE; j++) {
         if (mBoard[i][j] == 0) {
            
            list->push_back(new TicTacToeMove(i,j));
         }
      }
   }
}

void TicTacToeBoard::ApplyMove(GameMove *move) {
   TicTacToeMove *m = dynamic_cast<TicTacToeMove *>(move);
   mBoard[m->mRow][m->mCol] = GetNextPlayer();
   
   int r, c;
   int count = 0;
   
   for (int rowDelta = -1; rowDelta <= 1; rowDelta++) {
      for (int colDelta = -1; colDelta <= 1; colDelta++) {
         r = m->mRow + rowDelta;
         c = m->mCol + colDelta;
         
         while (InBounds(r, c) && mBoard[r][c] == GetNextPlayer() &&
                !THREE_IN_A_ROW && !(rowDelta == 0 && colDelta == 0)) {
            r += rowDelta;
            c += colDelta;
            count++;
            if (count == 2)
               THREE_IN_A_ROW = true;
         }
         
         if (mBoard[m->mRow - rowDelta][m->mCol - colDelta] == GetNextPlayer()
             && count == 1)
            THREE_IN_A_ROW = true;
         
         if (!THREE_IN_A_ROW)
            count = 0;
      }
      if (THREE_IN_A_ROW) {
         mValue = GetNextPlayer();
      }
   }
   mNextPlayer = GetNextPlayer() * -1;
   mHistory.push_back(m);
   
}

void TicTacToeBoard::UndoLastMove() {
   TicTacToeMove *m = dynamic_cast<TicTacToeMove *>(mHistory.back());
   
   mBoard[m->mRow][m->mCol] = 0;
   
   mNextPlayer = GetNextPlayer() * -1;
   delete mHistory.back();
   mHistory.pop_back();
}





