/*
Two properties of mod
    1) (a+b)(mod n) = (a(mod n) + b(mod n))(mod n), additative distributivity
    2) (a*b)(mod n) = (a(mod n) * b(mod n))(mod n), multiplicitive distributivity

    where above are congrouences

We know a number can be written as
    n = sigma a_i * 10^(ndigits - i)

    can write out n recursively as f_i = (10 * a_(ndigits - i)) + f_i-1, f_0=a_i is least signficant digit

    can then apply (1) to f to obtain large number mod n

Above is slightly wrong
    we need the first digit to have a_max * 10^ndigits, above will give a_max * 10^1

    to get a_max with 10 to correct power, traverse left to right (most to least significant)
*/

#include <bits/stdc++.h>

using namespace std;
using lt = unsigned long long;

lt large_mod_bad(const vector<lt>& v1, lt mod, lt i = 0)
{
    if (i == size(v1) - 1)
        return v1.back() % mod;

    return (((10 * v1[i]) % mod) + large_mod_bad(v1, mod, i + 1)) % mod;
}

lt large_mod(const vector<lt>& v1, lt mod)
{
    lt r = 0;
    for (lt l : v1)
        r = ((r * 10 + l) % mod);
    return r;
}

int main()
{
    cout << large_mod({1,7,3}, 7) << endl;
}
