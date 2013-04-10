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

SC_MODULE(Memory) {
    
    sc_in_clk CLK;
    sc_in<bool> LD;
    sc_in<bool> RW;
    sc_in<unsigned> X;
    sc_in<unsigned> Y;
    sc_inout_rv<32> D;
    
    SC_HAS_PROCESS(Memory);
    
    Memory(sc_module_name name) {
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
        
        SC_THREAD(data_thread);
        sensitive << CLK.neg();
    }
    
    void data_thread();
    
    void display() {
        for (int i = 0 ; i < SIZE ; ++i) {
            for (int j = 0 ; j < SIZE ; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    static const int SIZE = 8;
    
private:
    
    unsigned long** data;
    
};


#endif /* defined(__problem_1_1__Memory__) */
