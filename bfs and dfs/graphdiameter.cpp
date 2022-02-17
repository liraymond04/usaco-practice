#include <bits/stdc++.h>

using namespace std;

pair<int, int> bfs(vector<vector<int> > &adj, int start) {
    vector<bool> visited(adj.size());
    queue<pair<int, int> > q;

    int m = 0;

    q.push({start, 0});
    pair<int, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        visited[cur.first] = true;

        m = max(m, cur.second);
        for (const auto &v : adj[cur.first]) {
            if (!visited[v]) {
                q.push({v, cur.second + 1});
            }
        }
    }

    return cur;
}

int main() {
// 8 7
// 0 1
// 0 2
// 2 3
// 4 3
// 6 1
// 1 5
// 7 3
    int v, e;
    cin >> v >> e;

    vector<vector<int> > adj(v);
    for (int i=0; i<e; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    pair<int, int> f1 = bfs(adj, adj[0][0]);
    int ans = bfs(adj, f1.first).second;

    cout << ans;

    return 0;
}