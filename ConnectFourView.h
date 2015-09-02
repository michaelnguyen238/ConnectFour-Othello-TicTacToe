//
//  ConnectFourView.h
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#ifndef __Project3__ConnectFourView__
#define __Project3__ConnectFourView__

#include <stdio.h>
#include "ConnectFourBoard.h"
#include "GameView.h"
#include <iostream>

class ConnectFourView : public GameView {
   
   ConnectFourBoard *mConnectFourBoard;
   
   virtual void PrintBoard(std::ostream &s) const;
   
public:
   ConnectFourView(ConnectFourBoard *b) : mConnectFourBoard(b) {}
   
   friend std::ostream& operator<< (std::ostream &, const ConnectFourView &);
   
};

#endif /* defined(__Project3__ConnectFourView__) */
