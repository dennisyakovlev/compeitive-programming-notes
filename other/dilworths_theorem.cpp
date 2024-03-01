/*
Theorem
    dillworths theorem states for a finite size partially ordered set the largest antichain
    length is equal to the smallest disjoint chain decomposition

That is, taking the minimum number of disjoint LIS (chain) such that the set is paritioned is
    equal to the longest set where each element of the set is not comparable.
This question has a similar idea, but is not exact. Since have restriction that must pick up in
    order 1,2,...,n. But can still use antichain + disjoint chain decomposition idea.

The question is asking us to "sweep" the array left to right picking up increasing numbers in
    the order 1,2,...,n each time and to find the minium number of sweeos necessary. This is
    logically equavilent to smallest disjoint chain decomposition.
So we just need to find the largest antichain. 

Define the partial order to be
    v_i = v_j + 1, i < j

    => two elements are incomparable if v_i+1 comes before v_i
    => to find longest antichain find all elem for which elem+1 before it
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;
vector<lt> v;

void solve()
{
    set<lt> st = {v[0]};
    lt R=1;
    for (lt i=1;i!=n;++i) R+=st.count(v[i]+1), st.insert(v[i]);
    printf("%lld\n",R);
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin>>n;
    v.resize(n);
    for (lt i=0;i!=n;++i) cin>>v[i];
    solve();
}
