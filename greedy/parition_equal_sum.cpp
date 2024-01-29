/*
technique is keeping the sum the same
    -> pick the largest element for S1, second largest for S2
    -> then S1 is 1 greater
    -> to balance out, give second smallest to S2, smallest to S1
    -> this add 1 extra to S2
    -> diffs cancel out

Proof
    First, show when to apply technique

    Know sum(1,n) = n(n-1)/2
    Two cases
        sum odd
            => for all possible S1,S2 sets whose union is [n]
            => sum(S1) != sum(S2) (mod 2)
                -> since even+odd=odd is only possibility
        sum even
            => exists S1,S2 whose union is [n] and sums equal
                -> could be even+even or odd+odd
    So if sum(1,n) is odd, not possible to form two sets

    Let sum(1,n) be even.
        => n(n+1)/2 = 2a

        For n=0(mod 4)
            => form two pairs (1+i,n-i), (1+(i+1),n-(i+1))
            => (1+i)+(n-i) = 1+n = (1+(i+1))+(n-(i+1))
            => can do the same for i+2j inductively
            => sets are the same

        Check other three cases to see whats possible
        n=1(mod 4)
            => let N=4b+1
            => (4b+1)(4b+2)/2 = (16b^2+12b+2)/2 = 8b^2+6b+1
            => odd sum
            => not possible to parition into S1,S2
        n=2(mod 4)
            => let N=4b+2
            => (4b+2)(4b+3)/2 = (16b^2+20b+6)/2 = 8b^2+10b+3
            => odd sum
            => not possible
        n=3(mod 4)
            => let N=4b+3
            => (4b+3)(4b+4)/2 = (16b^2+28b+12)/2 = 8b^2+14b+6
            => even su,
            => possible

    So for n=3(mod 4), to apply technique must get n=0(mod 4) case.
        => for 1,2,3, parition into {1,2} and {3}
        => have now n-3=0(mod 4)
*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt n;

void solve()
{
    if (((n*(n+1))/2)%2)
    {
        printf("NO\n");
        return;
    }

    lt offset = 1;
    vector<lt> s1,s2;
    if (n%4==3)
    {
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);
        offset = 4;
    }

    lt halfway = n/2+(n%4?2:0);
    for (lt i=offset;i!=n+1;++i)
    {
        if ((i+(i>halfway))%2) s1.push_back(i);
        else s2.push_back(i);
    }

    printf("YES\n%ld\n", size(s1));
    for (lt i=0;i!=lt(size(s1));++i) printf("%lld ", s1[i]);
    printf("\n%ld\n", size(s2));
    for (lt i=0;i!=lt(size(s2));++i) printf("%lld ", s2[i]);
}

int main()
{
    cin>>n;
    solve();
}
