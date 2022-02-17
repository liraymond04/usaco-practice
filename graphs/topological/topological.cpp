#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > &adj, int s, vector<int> &result, vector<bool> &visited) {
    visited[s] = true;

    for (const auto &x : adj[s]) {
        if (visited[x]) continue;
        dfs(adj, x, result, visited);
    }
    result.insert(result.begin(), s);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n);
    for (int i=0; i<m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
    }

    vector<bool> visited(n, false);

    vector<int> result;
    for (int i=0; i<n; i++) {
        if (visited[i]) continue;
        dfs(adj, i, result, visited);
    }

    for (const auto &x : result) {
        cout << x << " ";
    }

    return 0;
}