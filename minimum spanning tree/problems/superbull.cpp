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
       return l.w < r.w;
    }
};


int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> teams(n);
    for (int i=0; i<n; i++) {
        cin >> teams[i];
    }

    vector<vector<Edge> > adj(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            adj[i].push_back({i, j, teams[i] ^ teams[j]});
            adj[j].push_back({j, i, teams[i] ^ teams[j]});
        }
    }

    priority_queue<Edge> pq;

    vector<bool> visited(n, false);

    long long ans = 0;

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
        ans += top.w;
        edges++;
    }

    cout << ans << "\n";

    return 0;
}