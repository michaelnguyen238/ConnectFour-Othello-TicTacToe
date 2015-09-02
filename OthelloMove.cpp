//
//  OthelloMove.cpp
//  Project 2
//
//  Created by Michael Nguyen on 4/17/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include <stdio.h>
#include "OthelloMove.h"
#include "GameExceptions.h"
#include "OthelloBoard.h"
#include <sstream>
#include <string>

using namespace std;

int OthelloMove::mOnHeap = 0;

OthelloMove::OthelloMove() {
   mRow = -1;
   mCol = -1;
}

OthelloMove::OthelloMove(int row, int col) : mRow(row), mCol(col) {}

GameMove& OthelloMove::operator=(const std::string &rhs) {
   
   istringstream iss(rhs);
   
   if (rhs == "pass") {
      mRow = -1;
      mCol = -1;
      return *this;
   }
   
   char buffer;
   
   iss >> buffer >> mRow >> buffer >> mCol >> buffer;
   
   if (mRow >= OTHELLO_BOARD_SIZE || mRow < 0
       || mCol >= OTHELLO_BOARD_SIZE || mCol < 0) {
      throw OthelloException("Move is out of bounds");
   }
   
   return *this;
}


OthelloMove::operator std::string() const {
   if (IsPass()) {
      return "pass";
   }
   ostringstream oss;
   oss << "(" << mRow << "," << mCol << ")";
   
   return oss.str();
}

bool OthelloMove::Equals(const GameMove &other) const {
   const OthelloMove &m = dynamic_cast<const OthelloMove &>(other);
   
   return (mRow == m.mRow && mCol == m.mCol);
}