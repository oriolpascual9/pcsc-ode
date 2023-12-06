#ifndef __READER_ODE__HH__
#define __READER_ODE__HH__

/* -------------------------------------------------------------------------- */
#include <iostream>
#include "Reader.hh"

class Reader_ODE: public Reader
{
public:

  Problem_ODE read_ODE_Problem() override;

};

/* -------------------------------------------------------------------------- */
#endif //__READER_ODE__HH__
