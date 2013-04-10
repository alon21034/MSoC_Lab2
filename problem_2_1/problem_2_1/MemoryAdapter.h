//
//  MemoryAdapter.h
//  problem_2_1
//
//  Created by Lee Haw on 13/4/10.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#ifndef __problem_2_1__MemoryAdapter__
#define __problem_2_1__MemoryAdapter__

#include <iostream>
#include "systemc.h"
#include "Mem_if.h"
#include "Memory.h"

SC_MODULE(MemoryAdapter), Mem_if {
    
    sc_in_clk CLK;
    sc_out<bool> LD;
    sc_out<bool> RW;
    sc_out<unsigned> X;
    sc_out<unsigned> Y;
    sc_inout_rv<32> D;
    
    MemoryAdapter(sc_module_name name) {
        size = Memory::SIZE;
    }
    
    void word_read(unsigned int, unsigned int, unsigned long&);
    void word_write(unsigned int, unsigned int, unsigned long);
    
    int size;
};

#endif /* defined(__problem_2_1__MemoryAdapter__) */
