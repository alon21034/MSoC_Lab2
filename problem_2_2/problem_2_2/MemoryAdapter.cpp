//
//  MemoryAdapter.cpp
//  problem_2_1
//
//  Created by Lee Haw on 13/4/10.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#include "MemoryAdapter.h"
#include <iostream>

using namespace std;

void MemoryAdapter::data_thread() {
    cout << "data thread start!!" << endl;
    
    for(;;) {
        while (LD->read() == false) {
            wait(LD->value_changed_event());
        }
        
        unsigned x = X->read();
        unsigned y = Y->read();
        
        wait(CLK.negedge_event());
        if (RW->read()) {
            //read
            unsigned long d;
            mem->word_read(x, y, d);
            D->write(d);
            wait(CLK.negedge_event());
        } else {
            //write
            unsigned long d = D->read().to_long();
            D->write("z");
            mem->word_write(x, y, d);
            //cout << "::" << x << " " << y << " " << d << endl;
            wait(CLK.negedge_event());
        }
    }
}