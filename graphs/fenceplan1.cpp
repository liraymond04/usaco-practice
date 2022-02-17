#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Cow> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    vector<vector<int> > adj(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f][t] = 1;
        adj[t][f] = 1;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}