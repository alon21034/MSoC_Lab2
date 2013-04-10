#include <systemc.h>
#include "consumer.h"

consumer::consumer(sc_module_name name) 
    : sc_module(name)
{
    SC_THREAD(main);
}

void consumer::main()
{
    char c;

    while (true) {
        if (!in->isEmpty()) {
            cout << "Read: Non blocking from" << sc_time_stamp();
            in->read(c);
            cout << " to " << sc_time_stamp() << endl;
        } else {
            cout << "Read: Blocking!! from " << sc_time_stamp();
            in->read(c);
            cout << " to " << sc_time_stamp() << endl;
        }
        wait(100, SC_NS);
    }
}
