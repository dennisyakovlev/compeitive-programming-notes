/*
Generate all prime numbers.

Typically used to generate prime factors. Can create all factors using
numbers <= sqrt(X).
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
vector<lt> primes;
 
void sieve()
{
    lt MX=10001; // is sqrt(max_val)
    vector<bool> seen(MX+1,false);
    for (lt i=2;i!=MX;++i)
    {
        if (!seen[i])
        {
            for (lt j=i;j<MX;j+=i) seen[j]=true;
            primes.push_back(i);
        }
    }
}

void solve()
{

}

int main()
{

}
