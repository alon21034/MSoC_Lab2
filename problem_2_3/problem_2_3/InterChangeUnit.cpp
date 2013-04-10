//
//  InterChangeUnit.cpp
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#include "InterChangeUnit.h"
#include <iostream>

using namespace std;

void InterChangeUnit::test_thread() {
    cout << "test thread start!!" << endl;
    

    unsigned long** buf = new unsigned long*[size];
    for (int i = 0 ; i < size ; ++i)
        buf[i] = new unsigned long[size];

    LD->write(false);
    wait(CLK.posedge_event());
    for (unsigned int i = 0 ; i < size; ++i) {
        for (unsigned int j = 0 ; j < size; ++j) {
            //read

            LD->write(true);
            RW->write(true);
            X->write(i);
            Y->write(j);
            wait(CLK.posedge_event());
            D->write("z");
            buf[i][j] = D->read().to_long();
           
            wait(SC_ZERO_TIME);
            LD->write(false);
        }
    }
    
    for (unsigned int i = 0 ; i < size ; ++i) {
        for (unsigned int j = 0 ; j < size ; ++j) {
            //write
            wait(CLK.posedge_event());
            LD->write(true);
            RW->write(false);
            X->write(i);
            Y->write(j);
            D->write(buf[j][i]);
            //cout << i << " " << j << " " << buf[j][i] << endl;
            wait(SC_ZERO_TIME);
            LD->write(false);
        }
    }
    
    LD->write(false);
}