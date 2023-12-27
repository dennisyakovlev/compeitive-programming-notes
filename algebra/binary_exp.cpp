/*
A number a^n can be expressed in two ways
    1) a^n = a^2k,    where k=n/2
    2) a^n = a^(b+c), where n=b+c

For case 1, this can be recurseively defined as
    a^n = a^2^2^2... where n is power of 2

    hence only need to do f_i * f_(i-1), f_0 = a, log2(n) times to get result

What about case 2?
    we know n is odd, otherwise use case 1
    => a^n = a^(2k+1) = a^(2k)*a
    => only need to multiply by a to get to case 1
    => O(log(n))
*/

#include <bits/stdc++.h>

using namespace std;
using lt = unsigned long long;

lt bin_exp(lt a, lt n)
{
    lt r = 1;
    while (n)
    {
        if (n % 2)
        {
            r *= a;
            n -= 1;
        }
        else
        {
            a *= a; // not r *= r since a^(2k+1) != (a^1)^(2k)
            n /= 2;
        }
    }
    return r;
}

lt bin_expr(lt a, lt n)
{
    if (n == 0)
        return 1;
    if (n % 2)
        return a * bin_expr(a, n - 1);
    lt r = bin_expr(a, n / 2);
    return r * r;
}

int main()
{
    cout << bin_exp(0, 5) << endl;
    cout << bin_exp(3, 1) << endl;
    cout << bin_exp(3, 2) << endl;
    cout << bin_exp(3, 3) << endl;
    cout << bin_exp(3, 4) << endl;
    cout << bin_exp(3, 7) << endl;
    cout << bin_exp(2, 10) << endl;
}
