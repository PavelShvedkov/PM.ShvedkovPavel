#include <iostream>
#include "BigInteger.h"

using namespace std;

int main()
{
    BigInteger a("1");
    BigInteger b("2");

    a.randomFill(10);
    b.randomFill(10);
    a.displaySum(b);

    a.randomFill(10);
    b.randomFill(5);
    a.displaySum(b);

    a.randomFill(5);
    b.randomFill(10);
    a.displaySum(b);
    
    a.randomFill(10);
    b.randomFill(5);
    a.displayDiff(b);

    a.randomFill(5);
    b.randomFill(10);
    a.displayDiff(b);
}

