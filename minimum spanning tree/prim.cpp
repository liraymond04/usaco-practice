#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u1, int v1, int w1) {
       u = u1;
       v = v1;
       w = w1;
    }
    friend bool operator < (const Edge& l, const Edge& r) {
       return l.w > r.w;
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge> > adj(n);
    for (int i=0; i<m; i++) {
        int f, t, w;
        cin >> f >> t >> w;
        adj[f].push_back({f, t, w});
        adj[t].push_back({t, f, w});
    }

    priority_queue<Edge> pq;

    vector<bool> visited(n, false);

    int cur = 0, edges = 0;
    while (edges < n-1) {
        visited[cur] = true;

        for (const auto &x : adj[cur]) {
            if (!visited[x.v]) pq.push(x);
        }
        
        Edge top = pq.top();
        while (visited[top.v]) {
            pq.pop();
            top = pq.top();
        }
        cur = top.v;
        cout << top.u << " " << top.v << " " << top.w << "\n";
        edges++;
    }

    return 0;
}