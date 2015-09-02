//
//  TicTacToeMove.h
//  Project3
//
//  Created by Michael Nguyen on 5/1/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#ifndef __Project3__TicTacToeMove__
#define __Project3__TicTacToeMove__

#include <stdio.h>
#include "GameMove.h"
#include <iostream>

class TicTacToeMove : public GameMove {
private:
   friend class TicTacToeBoard;
   
   int mRow, mCol;
   
   TicTacToeMove();
   
   TicTacToeMove(int row, int col);
   
public:

   virtual GameMove& operator=(const std::string &rhs);
   
   virtual operator std::string() const;
   
   virtual bool Equals(const GameMove &other) const;
   
   static int mOnHeap;
   
   static void* operator new(std::size_t sz){
      mOnHeap++;
      std::cout << "operator new: " << mOnHeap << " TicTacToeMoves on the heap" << std::endl;
      return ::operator new(sz);
   }
   
   static void operator delete(void* ptr, std::size_t sz) {
      mOnHeap--;
      std::cout << "operator delete: " << mOnHeap << " TicTacToeMoves on the heap" << std::endl;
      ::operator delete(ptr);
   }
   
   
};
#endif /* defined(__Project3__TicTacToeMove__) */
