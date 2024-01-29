/*
General idea is "find number of items which meet condition within a square on a 2d grid".

To solve, construct a grid and notice

    (1,1) (1,2) (1,3) (1,4) ... (1,n)
    (2,1) (2,2) (2,3) (2,4) ... (2,n)
    (3,1) (3,2) (3,3) (3,4) ... (3,n)
    (4,1) (4,2) (4,3) (4,4) ... (4,n)
     ...                         ...
    (m,1) (m,2) (m,3) (m,4) ... (m,n)

    is it easy to store the result for sqaures bounded by (1,1)+(row,col) using dp

    applying inclusion-exclusion princple we can see some square (r1,c1)+(r2,c2) with a<c and b<d
    knowing that squares of the form (1,1)+(row,col) are stored is
        1. add sqaure (1,1)+(r2,c2)
        2. subtract sqaure (1,1)+(r2,c1-1)
        3. subtract sqaure (1,1)+(r1-1,c2)
        4. add sqaure (1,1)+(r1-1,c1-1)

Proof
    its easy to see this works, as its just application of inclusion-exclusion principle
*/

#include <bits/stdc++.h>
 
using namespace std;
 
using lt = long long;
lt n,q;
vector<vector<char>> v;
vector<tuple<lt,lt,lt,lt>> qs;
 
void solve()
{
    vector<vector<lt>> dp(n+1,vector<lt>(n+1,0));
    for (lt c=1;c!=n+1;++c)
    {
        lt cr = 0;
        for (lt r=1;r!=n+1;++r)
        {
            cr += v[r-1][c-1] == '*';
            dp[r][c]=dp[r][c-1]+cr;
        }
    }
    for (const auto& [r1,c1,r2,c2] : qs)
    {
        lt s1 = dp[r2][c2];
        lt s2 = dp[r2][c1-1];
        lt s3 = dp[r1-1][c2];
        lt s4 = dp[r1-1][c1-1];
        printf("%lld\n", s1-s2-s3+s4);
    }
}
 
int main()
{
    cin>>n>>q;
    v.resize(n, vector<char>(n));
    qs.resize(q);
    for (lt i=0;i!=n;++i) for (lt j=0;j!=n;++j) cin>>v[i][j];
    for (lt i=0;i!=q;++i) cin>>get<0>(qs[i])>>get<1>(qs[i])>>get<2>(qs[i])>>get<3>(qs[i]);
    solve();
}

