/*
Dijkstra's algorithm finds a shortest path tree for some graph G, which is
    1) a tree (|V|-1=|E| and no cycles)
    2) a spanning tree (simple path for any u,v in V)
    3) from root r to v in V, simple path r -> v weights are minimized

The algorithm works only when weights are not negative. As the assumtion is for
any vertex marked as "visted", the path to this vertex is optimal. Negative weights
break this assumption.

Path restoration can be added by keeping track of all predessesor verticies

Proof:

    to be added

*/

// graph as adjency list, where pairs are (weight, next vertex)
// n is number of verticies
// sv is start vertex
void dijkstra(const vector<vector<pair<int,int>>>& adj, int n, int sv)
{
    set<pair<int,int>> s1;
    vector<int> d(n + 1, INT_MAX - SUM_MAX_WEIGHTS), p(n + 1, -1);

    s1.insert({0, sv});
    d[sv] = 0;

    while (size(s1))
    {
        int v = begin(s1)->second;
        s1.erase(begin(s1));

        for (auto [w, v_new] : adj[v])
        {
            if (d[v] + w < d[v_new])
            {
                s1.erase({d[v_new], v_new});
                d[v_new] = d[v] + w;
                s1.insert({d[v_new], v_new});

                p[v_new] = v;
            }
        }
    }
}

// predessors from algorithm
// start vertex
// end vertex
vector<int> restore(const vector<int>& p, int sv, int ev)
{
    vector<int> path;

    for (int v = ev; v != sv; v = p[v])
        path.push_back(v);
    path.push_back(sv);

    reverse(begin(path), begin(path));
    return path;
}
