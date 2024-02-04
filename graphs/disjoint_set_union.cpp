/*
the idea is to maintain a forest of tree roots with three operations
    make  - create a tree root, assume not already in set
    find  - find the root of a node, assume in a set
    merge - find roots of two nodes, attach one root to another root, assume both nodes in sets

two optimizations are
    1) for every find, update all traversed nodes to have root as parent
    2) merge the smaller size tree into the larger one
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> parent, set_size;

void make_set(int v)
{
    parent[v] = v;
    set_size[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void merge_sets(int v, int u)
{
    auto [a,b] = make_pair(find_set(v), find_set(u));
    if (a != b)
    {
        if (set_size[a] < set_size[b])
            swap(a,b);
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}

int main()
{
    parent.resize(5,0);
    set_size.resize(5, 0);

    make_set(1);
    make_set(2);
    make_set(3);
    make_set(4);

    merge_sets(1,2);
    merge_sets(3,2);
    merge_sets(4,2);
}
