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

void Memory::direct_read(unsigned long** &block) {
    block = data;
}

void Memory::direct_write(unsigned long** block) {
    for (int i = 0 ; i < SIZE ; ++i) {
        for (int j = 0 ; j < SIZE; ++j) {
            data[i][j] = block[i][j];
        }
    }
    
    display();
}

void Memory::word_read(unsigned x, unsigned int y, unsigned long& d) {
    assert(x < SIZE && y < SIZE);
    d = data[x][y];
}

void Memory::word_write(unsigned x, unsigned y, unsigned long d) {
    assert(x < SIZE && y < SIZE);
    data[x][y] = d;
}

void Memory::display() {
    for (int i = 0 ; i < SIZE ; ++i) {
        for (int j = 0 ; j < SIZE; ++j) {
            cout << data[i][j] << "  ";
        }
        cout << endl;
    }
}