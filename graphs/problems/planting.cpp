#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int> > &adj, int n) {
    vector<bool> visited(n+1, false);

    queue<int> q;
    q.push(1);

    int m = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        visited[cur] = true;

        int count = 0;
        for (const auto &x : adj[cur]) {
            if (!visited[x])
                q.push(x);
            count++;
        }
        m = max(m, count);
    }

    return m + 1;
}

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int> > adj(n+1);
    for (int i=0; i<n-1; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    cout << bfs(adj, n);
    
    return 0;
}