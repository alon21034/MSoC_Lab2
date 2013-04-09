//
//  Memory.h
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#ifndef __problem_1_1__Memory__
#define __problem_1_1__Memory__

#include <iostream>
#include "systemc.h"
#include "Mem_if.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

SC_MODULE(Memory), Mem_if {
    
    SC_CTOR(Memory) {
        srand(time(0));
        
        data = new unsigned long*[SIZE];
        for (int i = 0 ; i < SIZE; ++i) {
            data[i] = new unsigned long[SIZE];
            for (int j = 0 ; j < SIZE ; ++j) {
                data[i][j] = rand() % 256;
                cout << data[i][j] << "   ";
            }
            cout << endl;
        }
    }
    
    void direct_read(unsigned long**&);
    void direct_write(unsigned long**);
    
    void word_read(unsigned, unsigned, unsigned long&);
    void word_write(unsigned, unsigned, unsigned long);
    
    void display();
    
    static const int SIZE = 8;
    
private:
    
    unsigned long** data;
    
};


#endif /* defined(__problem_1_1__Memory__) */
