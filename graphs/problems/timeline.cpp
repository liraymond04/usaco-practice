// http://www.usaco.org/index.php?page=viewproblem2&cpid=1017

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;

    vector<int> events(n+1), in(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> events[i];
    }

    vector<vector<pair<int, int> > > adj(n+1);
    for (int i=0; i<c; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        in[b]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto &x : adj[cur]) {
            events[x.first] = max(events[x.first], events[cur] + x.second);
            
            in[x.first]--;
            if (in[x.first] == 0) {
                q.push(x.first);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << events[i] << "\n";
    }

    return 0;
}