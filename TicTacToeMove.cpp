//
//  TicTacToeMove.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/1/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include "TicTacToeMove.h"
#include "GameExceptions.h"
#include "TicTacToeBoard.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int TicTacToeMove::mOnHeap = 0;

TicTacToeMove::TicTacToeMove() {
   mRow = -1;
   mCol = -1;
}

TicTacToeMove::TicTacToeMove(int row, int col) : mRow(row), mCol(col) {}

GameMove& TicTacToeMove::operator=(const std::string &rhs) {
   istringstream iss(rhs);
   
   char buffer;
   
   iss >> buffer >> mRow >> buffer >> mCol >> buffer;
   
   if (mRow >= TIC_TAC_TOE_BOARD_SIZE || mRow < 0 ||
       mCol >= TIC_TAC_TOE_BOARD_SIZE || mCol < 0) {
      throw GameException("Move is out of bounds");
   }
   
   return *this;
}

TicTacToeMove::operator std::string() const {
   
   ostringstream oss;
   oss << "(" << mRow << "," << mCol << ")";
   
   return oss.str();
}


bool TicTacToeMove::Equals(const GameMove &other) const {
   const TicTacToeMove &m = dynamic_cast<const TicTacToeMove &>(other);
   
   return (mRow == m.mRow && mCol == m.mCol);

}

