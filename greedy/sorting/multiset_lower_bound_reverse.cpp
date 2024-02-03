/*
Technique:
    lower_bound and upper_bound can be used to find first element greater or equal
    to some value. however for sorted increasing can use
        lower_bound(rbegin,rend,val,greater{})
    to find largest element less than or equal to some val. the reverse iterators
    makes range descending. find "first" (closest to rbegin, ie end) element for
    which compare (greater(element,val)) is false. this is by definition the largest
    element <= val

    the same idea can be applied to sets. if we "reverse" the set by making it sorted
    descending, then its lower bound will act the same, finding the largest element
    <= val

Question: https://cses.fi/problemset/task/1091/ 
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n,m;
vector<lt> price,pay;

void solve()
{
    multiset<lt,greater<lt>> ms(begin(price),end(price));
    for (lt i=0;i!=m;++i)
    {
        auto it = ms.lower_bound(pay[i]);
        printf("%lld\n", it==end(ms)?-1:*it);
        if (it!=end(ms)) ms.erase(it);
    }
}

int main()
{
    cin>>n>>m;
    price.resize(n); pay.resize(m);
    for (lt i=0;i!=n;++i) cin>>price[i];
    for (lt i=0;i!=m;++i) cin>>pay[i];
    solve();
}
