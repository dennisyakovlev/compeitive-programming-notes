/*
floyd-warshall dp algorithm
    - O(|v|^3)
    - must set diagnol to 0

question: https://cses.fi/problemset/task/1672
video: https://www.youtube.com/watch?v=sdy6qXlB7g8&ab_channel=Dardeva
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m,q,INF=LLONG_MAX/2;
vector<vector<lt>> g;
vector<pair<lt,lt>> qs;

void solve()
{
    for (lt k=1;k!=n+1;++k)
    {
        for (lt i=1;i!=n+1;++i)
        {
            for (lt j=1;j!=n+1;++j)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for (auto [i,j] : qs) printf("%lld\n", g[i][j]==INF?-1:g[i][j]);
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt a,b,c;
    cin>>n>>m>>q;
    g.resize(n+1,vector<lt>(n+1,INF)), qs.resize(q);
    for (lt i=0;i!=n+1;++i) g[i][i]=0;
    for (lt i=0;i!=m;++i) cin>>a>>b>>c,g[a][b]=min(g[a][b],c), g[b][a]=min(g[b][a],c);
    for (lt i=0;i!=q;++i) cin>>a>>b,qs[i]={a,b};
    solve();
}
