/*
few key points to realize
    1. start shortest paths at 0
        => only negative weights have effect
        -> okay since only need negative cycle and not shortest path
    2. finding a vertex v which has unfinished relaxation on |V|th cycle gives
        1. v is on the negative cycle
            done, but show |V|-1 iterators do not leave cycle
            => p[v]=v'
            => v' on negative cycle by way it was set
            => indutively, v' will always be on cycle
        2. v is not on the negative cycle
            => exists path from v' on negative cycle to v
            => path length at most |V|-1
            => p[v]=v"
            => v" has unifinished relaxation by way it was set
            => path v' to v" exists
            => inductively apply until v"=v'
    3. must reverse found negative cycle since p[v] gives parent, which is opposite
        direction of the edge
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m;
const lt INF=LLONG_MAX/2;
vector<tuple<lt,lt,lt>> g; // g[i] = (from,to,weight)

void solve()
{
    vector<lt> dp(n+1,0), p(n+1,0); // dp[vetex] = min path, p[vertex] = parent
    for (lt i=0;i!=n;++i) for (auto [v,nv,w] : g) if (dp[v]+w<dp[nv]) dp[nv]=dp[v]+w, p[nv]=v;
    for (auto [v,nv,w] : g)
    {
        if (dp[v]+w<dp[nv])
        {
            lt start=v;
            for (lt i=0;i!=n-1;++i) start=p[start];

            vector<lt> cycle;
            for (lt cv=p[start];cv!=start;cv=p[cv]) cycle.push_back(cv);
            reverse(begin(cycle),end(cycle));
            printf("YES\n%lld ",start);
            for (lt v2 : cycle) printf("%lld ",v2);
            printf("%lld\n",start);
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt a,b,c;
    cin>>n>>m;
    g.resize(m);
    for (lt i=0;i!=m;++i) cin>>a>>b>>c, g[i]={a,b,c};
    solve();
}
