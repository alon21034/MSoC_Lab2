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
    
    unsigned long** data = 0;
    
    mem->direct_read(data);
    
    for (int i = 0 ; i < size; ++i) {
        for (int j = 0 ; j < size; ++j) {
            buf[i][j] = data[i][j];
        }
    }
    
    for (int i = 0 ; i < size ; ++i) {
        for (int j = i ; j < size ; ++j) {
            unsigned long temp = buf[i][j];
            buf[i][j] = buf[j][i];
            buf[j][i] = temp;
        }
    }
        
    mem->direct_write(buf);
}