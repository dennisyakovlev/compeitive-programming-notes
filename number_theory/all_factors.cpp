/*
Find all factors of X.
    -> use sieve to precomute all primes
    -> prime factorize
    -> multiply all possible combinations of prime factors together

O(log^2(X))
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
vector<lt> primes;

void solve()
{
    vector<lt> pf;
 
    lt x=X,I=0;
    while (x!=1&&I!=lt(size(primes)))
    {
        if (x%primes[I]==0)
        {
            pf.push_back(primes[I]);
            x/=primes[I];
        }
        else ++I;
    }
    if (x!=1) pf.push_back(x);

    unordered_set<lt> st; // all factors
    st.insert(1);
    for (lt i=0;i!=lt(size(pf));++i)
    {
        stector<lt> V;
        for (auto e : st) V.push_back(e*pf[i]);
        for (auto e : V) st.insert(e);
    }

    for (auto e : st) printf("%lld ", e);
}

int main()
{

}
