/*
bfs with path restoration
    - use parent array indiciating parent of node
    - the initial starting parent is always empty
    - must be careful adding duplicates to queue
        -> the moment added to queue, should be marked as seen
        -> if not going left / up then each going up / left will
           add a duplicate of up-left diagnol

question: https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt R,C,ra,ca,rb,cb;
vector<vector<char>> v;

bool valid(lt r, lt c)
{
    if (r<0||r>=R||c<0||c>=C) return false;
    bool b=v[r][c]!='#';
    if (v[r][c]!='B') v[r][c]='#';
    return b;
}

void solve()
{
    vector<vector<pair<lt,lt>>> p(R,vector<pair<lt,lt>>(C,{-1,-1}));
    deque<pair<lt,lt>> dq = {{ra,ca}};
    v[ra][ca]='#';
    while (size(dq))
    {
        lt sz=size(dq);
        for (lt i=0;i!=sz;++i)
        {
            auto [r,c] = dq.front();
            if (v[r][c]=='B') { rb=r,cb=c; goto done; } 
            dq.pop_front();
            if (valid(r-1,c)) dq.push_back({r-1,c}), p[r-1][c] = {r,c};
            if (valid(r+1,c)) dq.push_back({r+1,c}), p[r+1][c] = {r,c};
            if (valid(r,c+1)) dq.push_back({r,c+1}), p[r][c+1] = {r,c};
            if (valid(r,c-1)) dq.push_back({r,c-1}), p[r][c-1] = {r,c};
        }
    }
    printf("NO\n");
    return;

done:
    string s;
    auto [pr,pc] = p[rb][cb];
    while (pr!=-1)
    {
        if (pr<rb) s+='D';
        if (pr>rb) s+='U';
        if (pc<cb) s+='R';
        if (pc>cb) s+='L';
        tie(rb,cb) = make_pair(pr,pc);
        tie(pr,pc) = p[pr][pc];
    }
    reverse(begin(s),end(s));
    printf("YES\n%ld\n%s\n",size(s),s.c_str());
}

int main()
{
    cin>>R>>C;
    v.resize(R,vector<char>(C));
    for (lt r=0;r!=R;++r) for (lt c=0;c!=C;++c) { cin>>v[r][c]; if (v[r][c]=='A') ra=r,ca=c; }
    solve();
}
