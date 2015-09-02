//
//  TicTacToeView.h
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#ifndef __Project3__TicTacToeView__
#define __Project3__TicTacToeView__

#include <stdio.h>
#include "TicTacToeBoard.h"
#include "GameView.h"
#include <iostream>

class TicTacToeView : public GameView {
   
   TicTacToeBoard *mTicTacToeBoard;
   
   virtual void PrintBoard(std::ostream &s) const;
   
public:
   TicTacToeView(TicTacToeBoard *b) : mTicTacToeBoard(b) {}

};

#endif /* defined(__Project3__TicTacToeView__) */
