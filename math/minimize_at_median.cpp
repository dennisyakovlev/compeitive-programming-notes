/*
Theorem:
    sum(a_i - x) is minimized at median(a)

Question: https://cses.fi/problemset/task/1074
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;
vector<lt> v;

void solve()
{
    sort(begin(v),end(v));
    lt mid=n/2,R=0;
    for (lt i=0;i!=n;++i) R+=abs(v[mid]-v[i]);
    printf("%lld\n",R);
}

int main()
{
    cin>>n;
    v.resize(n);
    for (lt i=0;i!=n;++i) cin>>v[i];
    solve();
}
