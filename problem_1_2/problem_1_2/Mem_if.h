//
//  Mem_if,h.h
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#ifndef problem_1_1_Mem_if_h
#define problem_1_1_Mem_if_h

struct Mem_if: public sc_interface {
    
    virtual void direct_read(unsigned long**& block) = 0;
    virtual void direct_write(unsigned long** block) = 0;
    
    virtual void word_read(unsigned x, unsigned y, unsigned long& d) = 0;
    virtual void word_write(unsigned x, unsigned y, unsigned long d) = 0;
    
    virtual void display() = 0;
};

#endif
