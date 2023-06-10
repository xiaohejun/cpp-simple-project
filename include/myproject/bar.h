#ifndef BAR_H
#define BAR_H

#include "foo.h"

class Bar
{
private:
    int bar_var_;

public:
    int BarVal() const { return bar_var_; };

    int AddFooVal(const Foo &foo);
};

#endif