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
    
    for (unsigned int i = 0 ; i < size; ++i) {
        for (unsigned int j = 0 ; j < size; ++j) {
            mem->word_read(i, j, buf[i][j]);
        }
    }
    
    for (unsigned int i = 0 ; i < size ; ++i) {
        for (unsigned int j = 0 ; j < size ; ++j) {
            mem->word_write(j, i, buf[i][j]);
        }
    }
    
    mem->display();
}