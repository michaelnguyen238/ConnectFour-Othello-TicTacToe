//
//  ConnectFourBoard.h
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#ifndef __Project3__ConnectFourBoard__
#define __Project3__ConnectFourBoard__

#include <stdio.h>
#include <vector>
#include "ConnectFourMove.h"
#include "GameBoard.h"

const int MAX_ROWS = 6;
const int MAX_COLS = 7;

class ConnectFourBoard : public GameBoard {
public:
   
   enum Player {EMPTY = 0, YELLOW = 1, RED = -1};
   
   ConnectFourBoard();
   
   virtual void GetPossibleMoves(std::vector<GameMove *> *list) const;
   
   virtual void ApplyMove(GameMove *move);
   
   virtual void UndoLastMove();
   
   inline GameMove *CreateMove() const {return new ConnectFourMove;}
   
   inline static bool InBounds(int row, int col) {
      return row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS;
   }
   
   virtual bool IsFinished() const {
      return mHistory.size() == 42 || FOUR_IN_A_ROW;
   }

   
   std::string GetPlayerString(char player) {
      return (player == 1 ? "RED" : "YELLOW");
   }
   
private:
   friend class ConnectFourView;
   char mBoard[MAX_ROWS][MAX_COLS];
   bool FOUR_IN_A_ROW;

};

#endif /* defined(__Project3__ConnectFourBoard__) */
