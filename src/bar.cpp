#include "bar.h"

int Bar::AddFooVal(const Foo &foo)
{
    return bar_var_ + foo.FooVal();
}
