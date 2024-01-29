/*
This is hard one, i think its best to just memorize that
    G(n)=n^(n>>1)

Problem: https://cses.fi/problemset/task/2205
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;

void solve()
{
    for (lt i=0;i!=pow(2,n);++i)
    {
        lt j=i^(i>>1);
        for (lt k=n-1;k!=-1;--k) printf("%d", bool(j&(1<<k)));
        printf("\n");
    }
}

int main()
{
    cin>>n;
    solve();
}
