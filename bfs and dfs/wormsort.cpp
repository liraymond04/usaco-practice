// binary search from 0 (true) up until the last true which is the maximum minimum width

#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<pair<int, int> > > &adj, int x, int f, int t) {
    vector<bool> visited(adj.size()+1, false);

    queue<int> q;
    q.push(f);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == t) {
            return false;
        }
        // visited[cur] = true;
        for (pair<int, int> u : adj[cur]) {
            if (!visited[u.first] && x <= u.second) {
                q.push(u.first);
            }
        }
    }
    
    return true;
}

bool f(vector<int> &cows, vector<vector<pair<int, int> > > &adj, int x) {
    unordered_map<int, int> p;
    for (int i=0; i<cows.size(); i++) {
        if (cows[i] != i) {
            p[min(cows[i], i)] = max(cows[i], i);
        }
    }

    for (const auto m : p) {
        if (bfs(adj, x, m.first, m.second)) return false;
    }
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    bool sorted = true;
    vector<int> cows(n+1);
    for (int i=1; i<=n; i++) {
        cin >> cows[i];
        if (i != cows[i]) {
            sorted = false;
        }
    }

    if (sorted) {
        cout << -1;
        return 0;
    }

    int cap = 0;
    vector<vector<pair<int, int> > > adj(n+1);
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        cap = max(cap, w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int lo = 0, hi = cap;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(cows, adj, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    
    cout << lo;
    
    return 0;
}