//
//  ConnectFourView.cpp
//  Project3
//
//  Created by Michael Nguyen on 5/4/15.
//  Copyright (c) 2015 Michael Nguyen. All rights reserved.
//

#include "ConnectFourView.h"
#include <iostream>

using namespace std;

void ConnectFourView::PrintBoard(std::ostream &s) const {
   cout << "- 0 1 2 3 4 5 6";
   
   for (int i = 0; i < MAX_ROWS; i++) {
      cout << "\n" << i << " ";
      for( int j = 0; j < MAX_COLS; j++) {
         char temp = mConnectFourBoard->mBoard[i][j];
         if (temp == 0)
            cout << ". ";
         
         else if (temp == 1)
            cout << "R ";
         
         else if (temp == -1)
            cout << "Y ";
      }
   }
   cout << endl;
}

std::ostream& operator<< (std::ostream &lhs, const ConnectFourView &rhs) {
   rhs.PrintBoard(lhs);
   
   return lhs;
}