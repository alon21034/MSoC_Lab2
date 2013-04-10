//
//  Memory.cpp
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#include "Memory.h"

#include <iostream>
#include <assert.h>

using namespace std;

void Memory::data_thread() {
    cout << "data thread start!!" << endl;
    
    for(;;) {
        while (LD->read() == false) {
            wait(LD->value_changed_event());
        };
        
        //cout << "wait x, y, RW signal" << endl;
        unsigned x = X->read();
        unsigned y = Y->read();
        
        if (RW->read()) {
            // read
            //cout << "read: " << x << " " << y << " " << data[x][y] << endl;
            D->write(data[x][y]);
            wait(CLK.negedge_event());
        } else {
            // write
            D->write("z");
            wait(CLK.negedge_event());
            data[x][y] = D->read().to_long();
            //cout << data[x][y] << endl;
            //cout << "write: " << x << " " << y << " " << data[x][y] << endl;
            
        }
    }
}