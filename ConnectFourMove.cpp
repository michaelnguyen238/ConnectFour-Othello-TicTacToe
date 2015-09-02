//
//  ConnectFourMove.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include "ConnectFourMove.h"
#include "GameExceptions.h"
#include "ConnectFourBoard.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int ConnectFourMove::mOnHeap = 0;

ConnectFourMove::ConnectFourMove() {
   mCol = -1;
}

ConnectFourMove::ConnectFourMove(int col) : mCol(col) {}

GameMove& ConnectFourMove::operator=(const std::string &rhs) {
   istringstream iss(rhs);
   
   char buffer;
   
   iss >> buffer >> mCol >> buffer;
   
   if (mCol >= MAX_COLS || mCol < 0) {
      throw GameException("Move is out of bounds");
   }
   
   return *this;
}

ConnectFourMove::operator std::string() const {
   
   ostringstream oss;
   oss << "(" << mCol << ")";
   
   return oss.str();
}

bool ConnectFourMove::Equals(const GameMove &other) const {
   const ConnectFourMove &m = dynamic_cast<const ConnectFourMove &>(other);
   
   return (mCol == m.mCol);
   
}


