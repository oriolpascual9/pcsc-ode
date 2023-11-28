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

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  //! Documentation TODO
  Problem_ODE read_ODE_Problem();

};

/* -------------------------------------------------------------------------- */
#endif //__READER_ODE__HH__
