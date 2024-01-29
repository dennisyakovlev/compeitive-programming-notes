/*
recursive tree structure with O(lg(n)) operations. the tree cannot add or remove
elements but can update existing elements
    build(v, sl, sr, V)
        v  - current vertex number
        sl - current segment left
        sr - current segment right
        V  - array to use
    update(v, sl, sr, p, nv)
        v  - current vertex number
        sl - current segment left
        sr - current segment right
        p  - position in array of new value
        nv - new value to update
    query(v, sl, sr, l, r)
        v  - current vertex number
        sl - current segment left
        sr - current segment right
        l  - left of original query
        r  - right of original query

    notes on values of args
        v      - always initial call with 1, is 1-indexed
        sl, sr - 0-indexed inclusive, always 0,n-1 for first call
        p      - 0-indexed
        l,r    - 0 indexed inclusive, is range to query
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> T; // has 4*n elements

int build(int v, int sl, int sr, const vector<int>& V)
{
    if (sl == sr) return T[v] = V[sl];
    int m = (sl + sr) / 2;
    return T[v] = build(2*v, sl, m, V) + build(2*v+1, m+1, sr, V);
}

int update(int v, int sl, int sr, int p, int nv)
{
    if (p < sl || sr < p) return T[v];
    if (sl == sr) return T[v] = nv;
    int m = (sl + sr) / 2;
    return T[v] = update(2*v, sl, m, p, nv) + update(2*v+1, m+1, sr, p, nv);
}

int query(int v, int sl, int sr, int l, int r)
{
    if (l > r) return 0;
    if (l == sl && r == sr) return T[v];
    int m = (sl + sr) / 2;
    return query(2*v, sl, m, l, min(r,m)) + query(2*v+1, m+1, sr, max(l,m+1), r);
}

int main(int argc, const char* argv[])
{
    vector<int> v = {9,-8};
    int n = size(v);
    T.resize(4*n);
    build(1, 0, n-1, v);
    update(1, 0, n-1, 0, 3);
    printf("%d\n", query(1, 0, n-1, 1,1));

    //vector<int> v = {1,3,-2,8,-7};
    //int n = size(v);
    //
    //T.resize(4 * n, 0);

    //build(v, 1, 0, n-1);
    //printf("%d\n", query(1, 0, n-1, 1, 3));

    //update(1, 0, n-1, 0, 0);
    //printf("%d\n", query(1, 0, n-1, 1, 3));
    //printf("%d\n", query(1, 0, n-1, 0, n-1));
}
