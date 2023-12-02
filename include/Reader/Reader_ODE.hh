#ifndef __READER_ODE__HH__
#define __READER_ODE__HH__

/* -------------------------------------------------------------------------- */
#include <iostream>
#include "Reader.hh"

/**
  * Documentation TODO
  */

class Reader_ODE: public Reader
{
public:

  //! Documentation TODO
  Problem_ODE read_ODE_Problem() override;

};

/* -------------------------------------------------------------------------- */
#endif //__READER_ODE__HH__
