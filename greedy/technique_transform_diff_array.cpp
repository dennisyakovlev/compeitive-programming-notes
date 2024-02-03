/*
Technique: transform into different problem with an obvious invariant

let array d be defined as d_i=v_(i+1)-v_i
then it is obvious that v non-decreasing
    => d_i>=0 for 1<=i<=n-1

the problem now becomes easier
    -> operation on pair (v_i,v_(i+1)) translate to modifying (d_(i-1),d_(i+1))
        => d_even and d_odd are seperate
        =? can freely transfer within all d_even and all d_odd
    -> notice for i=1,n-1 the pairs in d are (NA,d_2),(d_(n-2),NA)
        => can modify d_2 and d_(n-2) alone
        => for |d|=even, can transfer all d_even into d_2 and all d_odd into d_(n-2)
        => |v|=odd can always turn d_i=0

        likewise for |v|=even
        => add d_odd can be transferred into either d_2,d_(n-2), since same parity
        => d_even should be over all >= 0
        => sum(d_even)>=0 -> sol exists, otherwise no

Question: https://codeforces.com/contest/1816/problem/C
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;
vector<lt> v;

bool solve()
{
    if (n%2) return true;
    lt R=0;
    for (lt i=0;i<n-1;i+=2) R+=v[i+1]-v[i];
    return R>=0;
}

int main()
{
    lt t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        v.resize(n);
        for (lt i=0;i!=n;++i) cin>>v[i];
        printf("%s\n", solve()?"YES":"NO");
    }
}
