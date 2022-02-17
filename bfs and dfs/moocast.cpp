#include <bits/stdc++.h>

using namespace std;

bool f(vector<vector<pair<long long, long long> > > &adj, long long x) {
    vector<bool> visited(adj.size(), false);

    queue<int> q;
    q.push(0);

    long long count = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visited[cur]) {
            continue;
        }
        count++;
        visited[cur] = true;
        for (pair<long, long> u : adj[cur]) {
            if (!visited[u.first] && u.second <= x) {
                q.push(u.first);
            }
        }
    }
    
    return count == adj.size();
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    long long d = 0, dd = INT_MAX;
    vector<pair<int, int> > cows(n);
    for (int i=0; i<n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    vector<vector<pair<long long, long long> > > adj(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            long long x = (cows[j].first - cows[i].first), y = (cows[j].second - cows[i].second);
            long long dist = x * x + y * y;
            d = max(d, dist);
            dd = min(dd, dist);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    long long lo = dd, hi = d;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (f(adj, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;
    
    return 0;
}