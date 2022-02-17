#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int> > &adj, vector<bool> &open, int start) {
    vector<bool> visited(adj.size());
    queue<int> q;

    int result = 0;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result++;

        for (const auto &v : adj[cur]) {
            if (!visited[v] && open[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return result;
}

bool check(vector<vector<int> > &adj, vector<bool> &open, int n, int m, int num, int i) {
    int start;
    for (start=1; start<=n; start++) {
        if (open[start]) {
            break;
        }
    }

    int target = n - i;
    int barns = bfs(adj, open, start);
    
    return target == barns;
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n+1);
    for (int i=0; i<m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    vector<bool> open(n+1, true);
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if (check(adj, open, n, m, num, i)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        open[num] = false;
    }
    
    return 0;
}