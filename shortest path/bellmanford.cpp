#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    friend bool operator < (const Edge& l, const Edge& r) {
       return l.w < r.w;
    }
};

struct Node {
    int u, dist;
    friend bool operator < (const Node& l, const Node& r) {
        return l.dist > r.dist;
    }
};

void relax(vector<int> &result, Edge edge) {
    int u = edge.u, v = edge.v, w = edge.w;
    if (result[v] > result[u] + w) {
        result[v] = result[u] + w;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }

    vector<int> result(n, INT_MAX);
    result[0] = 0;

    for (int i=1; i<n-1; i++) {
        for (int j=0; j<m; j++) {
            relax(result, edges[j]);
        }
    }

    for (int i=0; i<m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (result[v] > result[u] + w) {
            cout << "Graph contains negative edge" << "\n";
            break;
        }
    }

    return 0;
}