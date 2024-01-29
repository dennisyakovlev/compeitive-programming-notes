/*
The longest increasing subsequence of an array size n is defined as
    a_i1 < a_i2 < ... < a_ik for 1 <= i1 < i2 < ... < ik <= n

To solve use a dp array of size n + 1, where the answer is i, such that dp_i is not inital value
    dp[LIS length] = minimum ending num

Proof 
    for dp_i, it is only set when dp_(i-1) < a_j and a_j < dp_i
    by the way dp is constructed
        => all a_k will be offered to "compete" for every position in dp
        => by second condition alone, the minimal element will be placed into every dp position
    by first condition
        => dp_(i-1) < a_j
        => dp_(i-1) < dp_i
    since dp is increasing, do not need to search dp linearly, can use binary search
        to last dp_i < a_j, giving the LIS ending before a_j by definition of dp

The algorithm consists of a
    - dp array where dp[LIS length] = minimum ending value
    - iterating through all v_i, finding the longest lis from dp for which dp_i < v_i
        this works since dp values are increasing
    - if the condition dp_(i-1) < v_i and v_i < dp_i is met, update dp_i

To add sequence reconstruction need two extra arrays
    - ind where ind[LIS length] = index in v
    - p where p[index in v] = ind[2nd last num in LIS]
*/

#include <bits/stdc++.h>

using namespace std;

int lis_len(const vector<int>& v1)
{
    int len = 0;
    vector<int> dp(size(v1) + 1, INT_MAX);
    dp[0] = -1;
    for (int i = 0; i != size(v1); ++i)
    {
        int d = upper_bound(begin(dp), end(dp), v1[i]) - begin(dp);
        if (dp[d - 1] < v1[i] && v1[i] < dp[d])
        {
            dp[d] = v1[i];
            len = max(len, d);
        }
    }
    return len;
}

vector<int> lis_seq(const vector<int>& v1)
{
    int len = 0, n = size(v1);
    vector<int> dp(n + 1, INT_MAX), ind(n + 1, -1), p(n + 1, -1);
    dp[0] = -1; 
    for (int i = 0; i != size(v1); ++i)
    {
        int mlen = upper_bound(begin(dp), end(dp), v1[i]) - begin(dp);
        if (dp[mlen - 1] < v1[i] && v1[i] < dp[mlen])
        {
            dp[mlen] = v1[i];
            len = max(len, mlen);

            ind[mlen] = i;
            p[i] = ind[mlen - 1];
        }
    }

    vector<int> res(len);
    auto it = rbegin(res);
    *it++ = v1[ind[len]];
    for (int k = p[ind[len]]; k != -1; k = p[k])
        *it++ = v1[k];

    return res;
}

ostream& operator<<(ostream& out, const vector<int>& v)
{
    for (int i : v)
        out << i << " ";
    return out;
}

int main()
{
    cout << lis_len({1,2,3}) << endl;
    cout << lis_len({1,4,3}) << endl;
    cout << lis_len({10,9,2,5,3,7,101,18,105,8}) << endl;
    cout << lis_seq({1,2,3}) << endl;
    cout << lis_seq({1,4,3}) << endl;
    cout << lis_seq({10,9,2,5,3,7,101,18,105,8}) << endl;
}
