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

SC_MODULE(MemoryAdapter) {
    
    sc_port<Mem_if> mem;
    
    sc_in_clk CLK;
    sc_in<bool> LD;
    sc_in<bool> RW;
    sc_in<unsigned> X;
    sc_in<unsigned> Y;
    sc_inout_rv<32> D;
    
    SC_HAS_PROCESS(MemoryAdapter);
    
    MemoryAdapter(sc_module_name name) {
        size = Memory::SIZE;
        
        SC_THREAD(data_thread);
        
    }
    
    void data_thread();
    
    int size;
};

#endif /* defined(__problem_2_1__MemoryAdapter__) */
