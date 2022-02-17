#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int x, y, p;
};

int dfs(vector<vector<int> > &adj, vector<bool> &visited, int s) {
    visited[s] = true;

    int ans = 0;
    for (const auto &x : adj[s]) {
        if (visited[x]) continue;
        ans += dfs(adj, visited, x) + 1;
    }
    return ans;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<Cow> c(n);
    for (int i=0; i<n; i++) {
        cin >> c[i].x >> c[i].y >> c[i].p;
    }

    vector<vector<int> > adj(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int changey = c[j].y - c[i].y, changex = c[j].x - c[i].x;
            double dist = sqrt(changex * changex + changey * changey);
            if (dist <= c[i].p) {
                adj[i].push_back(j);
            }
            if (dist <= c[j].p) {
                adj[j].push_back(i);
            }
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        vector<bool> visited(n, false);
        int cows = dfs(adj, visited, i) + 1;
        ans = max(ans, cows);
    }

    cout << ans << "\n";

    return 0;
}