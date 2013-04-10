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

void Memory::word_read(unsigned x, unsigned int y, unsigned long& d) {
    assert(x < SIZE && y < SIZE);
    d = data[x][y];
}

void Memory::word_write(unsigned x, unsigned y, unsigned long d) {
    assert(x < SIZE && y < SIZE);
    data[x][y] = d;
}