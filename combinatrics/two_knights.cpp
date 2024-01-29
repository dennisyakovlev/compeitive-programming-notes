/*
Problem  - https://cses.fi/problemset/result/8314204/
Solution - https://math.stackexchange.com/questions/3266257/number-of-ways-two-knights-can-be-placed-such-that-they-dont-attack

Main idea is techinuqe where you take TOTAL - OVERCOUNT.
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;

void solve()
{
    for (lt k=1;k!=n+1;++k)
    {
        lt ttl = ((k*k)*((k*k)-1))/2;
        lt ovr = ((k-1)*(k-2) + (k-2)*(k-1)) * 2;
        printf("%lld\n", ttl-ovr);
    }
}

int main()
{
    cin>>n;
    solve();
}
