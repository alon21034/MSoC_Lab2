//
//  main.cpp
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#include "systemc.h"
#include "Memory.h"
#include "InterChangeUnit.h"

SC_MODULE(Top) {
    
    Memory memory;
    InterChangeUnit interChangeUnit;
    
    Top(sc_module_name name) :
    memory("memory"),
    interChangeUnit("inter_change_unit") {
        
        interChangeUnit.mem(memory);
        
    }
    
};


int sc_main (int argc, char * argv[]) {
			
    // insert code here...
    Top top("top");
    
    std::cout << "Hello, SystemC!\n";
    sc_start();
    return 0;
}

