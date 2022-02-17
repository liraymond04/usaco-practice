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

vector<int> build_path(vector<int> &from, int s, int t) {
    vector<int> result;

    int cur = t;
    while (cur != s) {
        result.push_back(cur);
        cur = from[cur];
    }
    result.push_back(cur);

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge> > adj(n);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w});
    }

    priority_queue<Node> pq;
    pq.push({0, 0});

    vector<bool> visited(n, false);

    vector<int> result(n, INT_MAX);
    result[0] = 0;

    vector<int> from(n, 0);

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int u = cur.u;
        visited[u] = true;

        for (const Edge &edge : adj[u]) {
            int dist = cur.dist + edge.w;
            if (dist < result[edge.v] && !visited[edge.v]) {
                pq.push({edge.v, dist});
                result[edge.v] = dist;
                from[edge.v] = u;
            }
        }
    }

    vector<int> path = build_path(from, 0, 4);
    for (const auto &x : path) {
        cout << x << " ";
    }

    return 0;
}