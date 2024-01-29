/*
Technique is to prove to yourself its deterministic, then can just count
To see is deterministic note that
    -> for some n, most optimal is to get largest to dest stack
    -> doing so requires [1,n-1] others to be off start stack
       and
       not on end stack
    -> means [1,n-1] should be on not dest and not start stack
    -> can redo this for n-1

Problem: https://cses.fi/problemset/task/2165
Answer:  https://www.youtube.com/watch?v=t5NXQlFIUuc&ab_channel=FastCodeDeveloper
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;
vector<pair<lt,lt>> v;

void dfs(lt from, lt to, lt help, lt rem)
{
    if (rem==0) return;
    dfs(from, help, to, rem-1); // current bottom to last stack
    v.push_back({from,to});
    dfs(help, to, from, rem-1); // all remaining to last stack
}

void solve()
{
    dfs(1,3,2,n);
    printf("%ld\n", size(v));
    for (auto [a,b] : v) printf("%lld %lld\n", a, b);
}

int main()
{
    cin>>n;
    solve();
}
