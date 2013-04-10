//
//  MemoryAdapter.cpp
//  problem_2_1
//
//  Created by Lee Haw on 13/4/10.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#include "MemoryAdapter.h"

void MemoryAdapter::word_read(unsigned x, unsigned y, unsigned long& d) {
    assert(x < size && y < size);
    
    LD->write(true);
    
    X->write(x);
    Y->write(y);
    RW->write(true);
    D->write("z");
    wait(CLK.posedge_event());
    wait(CLK.posedge_event());
    
    d = D->read().to_long();
    
    wait(SC_ZERO_TIME);
    
    LD->write(false);
}

void MemoryAdapter::word_write(unsigned x, unsigned y, unsigned long d) {
    assert(x < size && y < size);
    
    LD->write(true);
    
    X->write(x);
    Y->write(y);
    RW->write(false);
    
    //cout << x << " " << y << " " << d << endl;
    
    wait(CLK.posedge_event());
    
    D->write(d);
    
    wait(CLK.posedge_event());
    
    LD->write(false);
    
}