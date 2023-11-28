/*
find the numbers of times a digit d=[0,9] appears in the range [1,n]

idea is to traverse digits "D", least -> most signficant checking against d, seeing how
many times d appears in n at the current pos. there are two cases

    1) times d appears in n at the current pos for for numbers [0,next_D * 10^pos],
       excluding the most significant pos.
       ie number of times d appears for numbers less than the current traversed number
       plus one extra digit, rounded down to the next digit

            easy to caulcate. depending on position, d, everytime d appears it has
            a "weight", for example for pos=3 in 3425, d=4 will appear 3 times 4XX, 14XX, 24XX
            for numbers <= 3000 and everytime it appears, it will appear 100 times, so
            add 3 * 100 for this pos

    2) times d appears in digits at the current the pos for numbers [D * 10^pos, original_num[pos : 0]],
       including the signficant most digit
       ie number of times d appears for numbers less than the current traversed number but
       greater than that number rounded down to its most significant digit

        there are three cases 
            1) D < d => d appears 0 times for this position
                            
                            d=7 n=73453, position=3
                                => D=4
                                => 7 cannot appear in 100's digit for nums <= n[3 : 0] = 453

            2) D = d => d appears equal to number of numbers between previous power of 10
                        and current num, plus 1

                            d=4 n=73453, position=3
                                => D=4
                                => 4 appears once for every [400, n[3 : 0] = 453]

            3) D > d => d appears weight times for this position

                            d=2 n=73453, position=3
                                => D=4
                                => all of 2XX can be used
                                => 100 times (current weight)

*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;
lt d, n;

lt num_digits()
{
    lt r = 0, m = 1, N = n;
    while (n)
    {
        // times appears gaurenteed * value of each appeareance
        r += ((N / (10 * m)) - (d == 0)) * m;

        if (n % 10 == d)     // digit will appear equal to number right of digit times
            r += 1 + (N % m); 
        else if (n % 10 > d) // digit will appear value of each appeareance times
            r += m;

        n /= 10;
        m *= 10;
    }
    return r;
}

lt solve()
{
    return num_digits();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> d >> n;
        cout << solve() << endl;

    }
}
