#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w, f;
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

double shortest_path(vector<vector<Edge> > &adj, int f, int n) {
    priority_queue<Node> pq;
    pq.push({1, 0});

    vector<bool> visited(n+1, false);

    vector<int> result(n+1, INT_MAX);
    result[1] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int u = cur.u;
        if (u == n) {
            break;
        }
        visited[u] = true;

        for (const Edge &edge : adj[u]) {
            if (edge.f < f) {
                continue;
            }
            int dist = cur.dist + edge.w;
            if (dist < result[edge.v] && !visited[edge.v]) {
                pq.push({edge.v, dist});
                result[edge.v] = dist;
            }
        }
    }

    return result[n];
}

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge> > adj(n+1);
    for (int i=0; i<m; i++) {
        int u, v, w, f;
        cin >> u >> v >> w >> f;
        adj[u].push_back({u, v, w, f});
        adj[v].push_back({v, u, w, f});
    }

    double ans = 0;
    for (double i=1; i<=1000; i++) {
        ans = max(ans, i / shortest_path(adj, i, n));
    }

    int result = ans * 10e5;

    cout << result << "\n";

    return 0;
}