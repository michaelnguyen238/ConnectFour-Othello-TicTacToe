//
//  TicTacToeBoard.h
//  Project3
//
//  Created by Michael Nguyen on 5/1/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#ifndef __Project3__TicTacToeBoard__
#define __Project3__TicTacToeBoard__

#include <stdio.h>
#include <vector>
#include "TicTacToeMove.h"
#include "GameBoard.h"



const int TIC_TAC_TOE_BOARD_SIZE = 3;

class TicTacToeBoard : public GameBoard {
public:
   
   enum Player {EMPTY = 0, X = 1, O = -1};
   
   TicTacToeBoard();
   
   virtual void GetPossibleMoves(std::vector<GameMove *> *list) const;
   
   virtual void ApplyMove(GameMove *move);
   
   virtual void UndoLastMove();
   
   inline GameMove *CreateMove() const {return new TicTacToeMove;}
   
   inline static bool InBounds(int row, int col) {
      return row >= 0 && row < TIC_TAC_TOE_BOARD_SIZE &&
      col >= 0 && col < TIC_TAC_TOE_BOARD_SIZE;
   }
   
   virtual bool IsFinished() const {
      return mHistory.size() == 9 || THREE_IN_A_ROW;
   };
   
   std::string GetPlayerString(char player) {
      return (player == 1 ? "X" : "O");
   }
   
   
private:
   friend class TicTacToeView;
   char mBoard[TIC_TAC_TOE_BOARD_SIZE][TIC_TAC_TOE_BOARD_SIZE];
   bool THREE_IN_A_ROW;
   
};

#endif /* defined(__Project3__TicTacToeBoard__) */
