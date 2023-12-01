#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

struct Exception {

    Exception(const std::string &mesg) : mesg(mesg){};
    const std::string &what() { return mesg; };
    std::string mesg;

};

#endif //EXCEPTION_HANDLER_H
