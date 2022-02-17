#include <bits/stdc++.h>

using namespace std;

int checkSink(vector<vector<int> > &adj, int num, int n) {
    for (int i=0; i<n; i++)
        if (adj[num][i]) return 0;
    for (int i=0; i<n; i++)
        if (i != num && !adj[i][num]) return 0;
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n, vector<int>(n, 0));
    for (int i=0; i<m; i++) {
        int f, t;
        cin >> f >> t;
        adj[f][t] = 1;
    }

    int sink = 0, pos = 0, found = 0;
    while (sink < n && pos < n) {
        if (adj[sink][pos] == 1) {
            sink++;
        } else {
            pos++;
        }
    }
    if (sink < n && checkSink(adj, sink, n)) {
        found = 1;
    }

    if (found) {
        cout << sink << "\n";
    } else {
        cout << "no universal sink" << "\n";
    }

    return 0;
}