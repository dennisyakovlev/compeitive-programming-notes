/*
bellman-ford sinle source shortest path with negative weights
    -> turn shorest into longest
    -> look for positive cycle
    -> positive cycle must be on path from 1 to n

theorem
    a graph contains no negative cycles iff all relaxations are optimal after |v|-1 iterations

proof
    let G be graph with no negative cycles
        => know the diameter of any graph is < |v|
        => a relaxtion can progigate < |v| times
        => after |v|-1 iterations, the weights for G are optimal
    now let G have a negative cycle
        => infinite number of progigations can be done within the cycle
        => on the |v|-1'th iteration, have a relaxation

=== second part ===

for this problem specifcally the cycle must be on a path {1,...,n}
to find which edges in a graph are on the path {1,...,n}

technique:
        -> make the graph directed, going in two directions
            1. from 1 to n
            2. from n to 1
        -> traverse from both 1->n on graph 1 anf n->1 on graph 2
        -> keep track of which veticies seen
        -> vertex which is seen on both is part of {1,...,n} path

proof:
    ???

question: https://cses.fi/problemset/task/1673
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m,INF=LLONG_MIN/2;
vector<tuple<lt,lt,lt>> e; // edge = (vertex 1, vertex 2), edge weight 
vector<vector<lt>> v1,v2;
vector<lt> s1, s2;

void dfs1(lt cv)
{
    if (s1[cv]) return;
    s1[cv]=1;
    for (auto nv : v1[cv]) dfs1(nv);
}

void dfs2(lt cv)
{
    if (s2[cv]) return;
    s2[cv]=1;
    for (auto nv : v2[cv]) dfs2(nv);
}

void solve()
{
    s1.resize(n+1,0), s2.resize(n+1,0);
    dfs1(1), dfs2(n);

    vector<lt> dp(n+1,INF);
    dp[1]=0;
    for (lt i=0;i!=n-1;++i) for (auto [a,b,c] : e) if (dp[a]!=INF) dp[b]=max(dp[a]+c,dp[b]);
    for (auto [a,b,c] : e) if (s1[a]+s2[a]==2 && dp[b]<dp[a]+c) { printf("-1\n"); return; }
    printf("%lld\n",dp[n]);
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt a,b,c;
    cin>>n>>m;
    v1.resize(n+1), v2.resize(n+1), e.resize(m);
    for (lt i=0;i!=m;++i) cin>>a>>b>>c, e[i]=make_tuple(a,b,c), v1[a].push_back(b), v2[b].push_back(a);
    solve();
}
