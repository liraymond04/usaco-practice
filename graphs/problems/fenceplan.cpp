#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int x, y;
};

// vector<vector<int> > graphTranspose(vector<vector<int> > &adj) {
//     vector<vector<int> > result(adj.size());

//     for (int i=1; i<=adj.size(); i++) {
//         for (const auto &x : adj[i]) {
//             result[x].push_back(i);
//         }
//     }

//     return result;
// }


int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);


    int n, m;
    cin >> n >> m;

    vector<Cow> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    vector<vector<int> > adj(n+1);
    for (int i=1; i<=m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    int ans = INT_MAX;
    vector<bool> visited(n+1, false);
    for (int i=1; i<=n; i++) {
        if (visited[i]) {
            continue;
        }

        queue<int> q;
        q.push(i);
        
        int xmin = INT_MAX, xmax = 0, ymin = INT_MAX, ymax = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            xmin = min(xmin, v[cur].x);
            xmax = max(xmax, v[cur].x);
            ymin = min(ymin, v[cur].y);
            ymax = max(ymax, v[cur].y);
            
            visited[cur] = true;
            for (const auto &x : adj[cur]) {
                if (!visited[x]) {
                    q.push(x);
                }
            }
        }
        int perim = (xmax - xmin) * 2 + (ymax - ymin) * 2;
        ans = min(ans, perim);
    }

    cout << ans << "\n";

    // adj = graphTranspose(adj);

    // for (int i=1; i<=n; i++) {
    //     cout << i << ": ";
    //     for (const auto &x : adj[i]) {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}