/*

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> parents, sizes;

int find(int n)
{
    if (n == parents[n])
        return n;
    return parents[n] = find(parents[n]);
}

void merge(int n, int m)
{
    auto [a,b] = make_pair(find(n), find(m));
    if (a != b)
    {
        if (sizes[a] < sizes[b])
            swap(a,b);
        parents[b] = a;
        sizes[a] += sizes[b];
    }
}

int kruskals(vector<tuple<int,int,int>>& v1, int n)
{
    parents.resize(n);
    sizes.resize(n, 1);
    iota(begin(parents), end(parents), 0);

    sort(begin(v1), end(v1));

    int r = 0, e = 0;
    for (const auto& [w,a,b] : v1)
    {
        if (find(a) != find(b))
        {
            merge(a, b);
            r += w;
            ++e;
        }
        if (e == n - 1)
            break;
    }
    return r;
}

int minCostConnectPoints(const vector<vector<int>>& v1)
{
    vector<tuple<int,int,int>> v2;
    for (int i = 0; i != size(v1); ++i)
    {
        for (int j = i + 1; j != size(v1); ++j)
        {
            int d = abs(v1[i][0] - v1[j][0]) + abs(v1[i][1] - v1[j][1]);
            v2.push_back(make_tuple(d, i, j));
        }
    }

    return kruskals(v2, size(v1));
}

int main()
{
    minCostConnectPoints({{0,0},{2,2},{3,10},{5,2},{7,0}});
}
