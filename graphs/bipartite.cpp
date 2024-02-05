/*
Bipartite graph problem. We are coloring the graph into 2 colors.

Theorem
    a graph is bipartite iff all cycles are even length

technique
    we can check if all cycles are even length, but easier would be
    to just color the graph and check for contradictions

proof: https://www.whitman.edu/mathematics/cgt_online/book/section05.04.html
question: https://cses.fi/problemset/task/1668
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m;
vector<vector<lt>> g;
vector<lt> col;

bool dfs(lt v, lt pv, lt c)
{
    if (col[v] && col[v]!=c) return true;
    if (col[v]) return false;
    col[v]=c;
    for (auto nv : g[v]) if (nv != pv) if (dfs(nv,v,c==1?2:1)) return true;
    return false;
}

bool solve()
{
    col.resize(n+1,0);
    for (lt i=1;i!=n+1;++i) if (col[i]==0 && dfs(i,-1,1)) return true;
    for (lt i=1;i!=n+1;++i) printf("%lld ", col[i]);
    printf("\n");
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt a,b;
    cin>>n>>m;
    g.resize(n+1);
    for (lt i=0;i!=m;++i) cin>>a>>b, g[a].push_back(b), g[b].push_back(a);
    if (solve()) printf("IMPOSSIBLE\n");
}
