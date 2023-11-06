/*
the gcd of two numbers a,b is denoted (a,b) = d
    where d|a and d|b and d is maximal

we know d|(a-b)
    => d|(a-kb)
    => d|c, such that a=c(mod b)

then define recursively
                gcd(a, a % b)  if !(b|a)
    gdc(a,b) =
                b              if b|a
    where a >= b

    to make sure a is always larger, swap a and b with every recursive
    iteration. this is okay since
        a > b => a % b decreases
        a < b => a % b same, will decrease next call
*/

#include <bits/stdc++.h>

using namespace std;
using Lt = unsigned long long;

Lt gcd(Lt a, Lt b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
    cout << gcd(21, 49) << endl;
    cout << gcd(245, 49) << endl;
    cout << gcd(3, 7) << endl;
}
