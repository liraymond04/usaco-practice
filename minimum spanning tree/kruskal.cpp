#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    friend bool operator < (const Edge& l, const Edge& r) {
       return l.w < r.w;
    }
};

int find(vector<int> &parent, int x) {
    if (parent[x] == x) {
        return x;
    } else {
        int p = find(parent, parent[x]);
        parent[x] = p;
        return p;
    }
}

bool union2(vector<int> &parent, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);

    if (pu == pv) {
        return false;
    } else {
        parent[pu] = pv;
        return true;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i=0; i<m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());

    int num = 0;

    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }

    for (const auto &x : edges) {
        if (union2(parent, x.u, x.v)) {
            cout << x.u << " " << x.v << " " << x.w << "\n";
            num++;
        }
        
        if (num == n-1) {
            break;
        }
    }

    return 0;
}