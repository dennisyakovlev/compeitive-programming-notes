/*
Theorem:
    a cycle exsists iff a path of the form {v',v1,v2,...,vn,v'} exists
 
This gives us the solution that for path of above form
    => dfs
    => if see seen v' in a single dfs
        => have cycle
The path restore proof is also trivial
    p[v] is set once
        => is correct
 
cycle_end is needed since do not want to reset parent of S, since it may have
path going into it we wish to keep.
 
To restore cycle, start at end, checking parent until start.

Question: https://cses.fi/problemset/task/1669/
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m,cycle_start,cycle_end,a,b;
vector<vector<lt>> g;
vector<lt> visited, parent,cycle;

bool unidrected_dfs(lt v, lt pv)
{
    visited[v]=1;
    for (auto nv : g[v])
    {
        if (nv!=pv)
        {
            if (visited[nv]) { cycle_start=nv, cycle_end=v; return true; }
            if (unidrected_dfs(nv, parent[nv]=v)) return true;
        }
    }
    return false;
}

void solve()
{
    visited.resize(n+1,0), parent.resize(n+1,-1);
    cycle_start=-1;
    for (lt i=1;i!=n+1;++i) if (!visited[i] && unidrected_dfs(i,parent[i])) break;

    if (cycle_start==-1) printf("IMPOSSIBLE\n");
    else
    {
        cycle.push_back(cycle_start);
        for (lt v=cycle_end; v!=cycle_start; v=parent[v]) cycle.push_back(v);
        cycle.push_back(cycle_start);

        printf("%ld\n", size(cycle));
        for (lt i=0;i!=lt(size(cycle));++i) printf("%lld ", cycle[i]);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin>>n>>m;
    g.resize(n+1);
    for (lt i=0;i!=m;++i) cin>>a>>b, g[a].push_back(b), g[b].push_back(a);
    solve();
}
