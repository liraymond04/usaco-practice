#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &s, int x) {
    if (x == s[x]) {
        return x;
    } else {
        int p = find(s, s[x]);
        s[x] = p;
        return p;
    }
}

bool unite(vector<int> &s, vector<int> &size, int x, int y) {
    int px = find(s, x), py = find(s, y);

    if (px == py) {
        return false;
    } else {
        if (size[px] < size[py]) {
            s[px] = py;
            size[py] += size[px];
            return true;
        } else {
            s[py] = px;
            size[px] += size[py];
            return true;
        }
    }
}

int main() {
    // freopen("closing.in", "r", stdin);
    // freopen("closing.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n+1);
    vector<pair<int, int> > edge(m);
    for (int i=0; i<m; i++) {
        int f, t;
        cin >> f >> t;
        edge[i] = {f, t};
    }

    vector<int> remove(n), order(n);
    for (int i=n-1; i>=0; i--) {
        cin >> remove[i];
        order[remove[i]] = i;
    }

    for (int i=0; i<m; i++) {
        int f = edge[i].first, t = edge[i].second;
        if (order[f] > order[t]) {
            adj[f].push_back(t);
        } else {
            adj[t].push_back(f);
        }
    }

    vector<string> ans;

    vector<int> s(n+1), size(n+1);
    for (int i=1; i<=n; i++) {
        s[i] = i;
    }

    int roots = 0;
    for (int cur : remove) {
        roots++;
        for (int r : adj[cur]) {
            if (unite(s, size, cur, r)) {
                roots--;
            }
        }
        if (roots == 1) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }

    for (int i=n-1; i>=0; i--) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}