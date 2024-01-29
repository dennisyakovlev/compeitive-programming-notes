/*
This is combinatorical problem where we must find all permutations of the given
    letters not counting repitions. Thats is, aab=aab, even though 123!=213.

The number of such strings is
    total / overcount
        -> total = n!
        -> over = product(freq each char!)

Can start at the lexigraphical minimimal permutation and continue to largest.
    -> there is [next_permutation] from STL
    -> implement our own

Proof of next permutation
    definition of lexigraphical ordering
        => attempt to modify largest index, say j
    but next largest
        => s_j must be set to minimal of s_k, j+1<=k<=n
        and
        => s_j' must increase from s_j
            => increasing (or non-decreasing for non-unique elems) sequence from [n,1]
               cannot be modified
            => find first element which is decreasing, gives our j
            => find i in [j+1,n] which s_i>s_j
                -> swap i,j
                -> know [j+1,n] is increasing, so can pick first element from end which
                   satisfies s_i>s_j
            => s_j' the next lexigrpahically min possible
    but need s to be lex min
        => know [j+1,n] is increasing when traversed n to 1
        => [j+1,n] is lexigraphically max
        => reverse [j+1,n] to get lex min
        => j and [j+1,n] is lex min
        => s is lex minimal next largest

Question: https://cses.fi/problemset/task/1622/
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
string S;

lt fac(lt N) { return N?fac(N-1)*N:1; }

void nperm(string& s)
{
    if (size(s)<=1) return;
    lt n=size(s),i=n-1,j=n-1;
    for (; i!=0 && s[i-1]>=s[i]; --i);   // first decreasing pair
    for (; j!=i-1 && s[j]<=s[i-1]; --j); // smallest can swap with
    if (i!=0) swap(s[i-1],s[j]);         // i=0 => lex largest
    reverse(begin(s)+i,end(s));
}

void solve()
{
    vector<lt> v(26,0);
    lt T=fac(size(S)), O=1, A;
    for (char c : S) ++v[c-'a'];
    for (auto e : v) O*=fac(e);
    A=T/O;

    cout<<A<<endl;
    sort(begin(S),end(S));
    for (lt i=0;i!=A;++i)
    {
        cout<<S<<endl;
        nperm(S);
    }
}

int main()
{
    cin>>S;
    solve();
}
