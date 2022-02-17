#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> in(n, 0);

    vector<vector<int> > adj(n);
    for (int i=0; i<m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        in[t]++;
    }

    queue<int> q;
    for (int i=0; i<n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);
        for (const auto &x : adj[cur]) {
            in[x]--;
            if (in[x] == 0) {
                q.push(x);
            }
        }
    }

    for (const auto &x : result) {
        cout << x << " ";
    }

    // minimum spanning tree, dijkstra, shortest path

    return 0;
}