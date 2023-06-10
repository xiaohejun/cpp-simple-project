#include <iostream>
#include "bar.h"

using namespace std;

int main()
{
    Foo foo;
    Bar bar;
    bar.AddFooVal(foo);
    cout << "bar_bar_val_: " << bar.BarVal() << endl;
    return 0;
}