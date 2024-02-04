/*
Generate all prime numbers.

Typically used to generate prime factors. Can create all factors using
numbers <= sqrt(X).
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
vector<bool> primes; // primes[i] = true => is prime
 
void sieve()
{
    lt MX=10001; // is sqrt(max_val)
    primes.assign(MX+1,true);
    for (lt i=2;i!=MX;++i)
        if (primes[i])
            for (lt j=2*i;j<MX;j+=i) primes[j]=false;
}

void solve()
{

}

int main()
{
    sieve();
}
