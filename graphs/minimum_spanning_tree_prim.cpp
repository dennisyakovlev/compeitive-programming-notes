/*
A minimum spanning tree is subgraph from a connected graph G such that
    1) it is a tree (|E| = |V| - 1 and no cycles)
    2) sum of edge weights is minimal from G

Kruskal's algorithm finds the MST by
    - sorting all edges in non-decreasing order of weight
    - find the |V|-1 edges from least to greatest
    - an edge is not added if is already in the current MST

The issue becomes how to keep track of "current MST"
    - use disjoint set union

But the DSU has a forest of trees, how do we know this works is actually building an MST?
Proof by Induction
    Let S be the current set of edges at any point in the algroithm.
    Let T be some MST.
    
    Claim: S is subset of some MST

    Base: S = {}, since null set is always subset, works

    Inductive Step: Potentially add an edge e to S, there are 3 cases
        1) e in T, then S + e is MST
        2) S + e creates cycle, do not add e
        3) e not in T, have S + e. But is S + e a valid MST ?
           consider T + e, since T is tree and e not in T, T + e has a cycle C
           there exists e' on C such that e' not in S (since S != T and the way S is constructed)
           consider T - e' + e
                know weights e' = e, otherwise
                1) w(e') > w(e) => w(T - e' + e) < w(T) => T is not MST, which is false by definition of T
                2) w(e') < w(e) => e' would have been picked already
           then w(T - e' + e) = w(T) => w(T - e' + e) is MST
           then S subset T and e' not in S => S + e subset T - e' + e 

        S remains valid subset of T


Some properties of a MST
    1) if edges are all unique, MST is unique
    2) MST is also MST for product of all edge weights, not just sum
    3) maximum spanning tree can be found by inverting signs on all weights
*/

#include <bits/stdc++.h>

using namespace std;


int mst(const vector<tuple<int,int,int>> edges, int n) // (weight, vertex, vertex), num verticies
{
    sort(begin(edges), end(edges));

    int r = 0;
    for (auto [w,a,b] : edges)
    {
        if (union_find(a) != union_find(b))
        {
            r += w;
            union_merge(a,b);
        }
    }
    return r;
}

int main()
{

}
