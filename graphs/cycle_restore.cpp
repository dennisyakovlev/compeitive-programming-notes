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

Mark the cycle with
    L - number of edges
    S - entrance to cycle with the dfs
    E - one before end of cycle
E is needed since do not want to reset parent of S, since it may have
path going into it we wish to keep.

To restore cycle, start at E, checking for parent L times.
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m,S=0,E=0,L=0; 
vector<vector<lt>> g;
vector<lt> p;

lt dfs(lt v, lt pv)
{
    if (p[v] && p[v]!=pv) return 5+((S=v)&&(E=pv)&&++L);
    if (p[v]) return 0;
    p[v]=pv;
    lt t;
    for (auto nv : g[v]) if (nv!=pv) if ((t=dfs(nv,v))) return v==S||t==1?1:++L;
    return 0;
}

lt solve()
{
    p.resize(n+1,0);
    for (lt i=1;i!=n+1;++i) if (p[i]==0 && dfs(i,-1)) break;
    if (L==0) return 0;
    lt v=E;
    printf("%lld\n",L+1);
    for (lt i=0;i!=L;++i) printf("%lld ",v), v=p[v];
    printf("%lld",E);
    return 1;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt a,b;
    cin>>n>>m;
    g.resize(n+1);
    for (lt i=0;i!=m;++i) cin>>a>>b, g[a].push_back(b), g[b].push_back(a);
    if (!solve()) printf("IMPOSSIBLE");
    printf("\n");
}
