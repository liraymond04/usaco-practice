#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    friend bool operator < (const Edge& l, const Edge& r) {
       return l.w > r.w;
    }
};

struct Query {
    int k, v, i;
    friend bool operator < (const Query& l, const Query& r) {
       return l.k > r.k;
    }
};

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
    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<Edge> edges(n-1);
    vector<Query> queries(q);

    for (int i=0; i<n-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        edges[i] = {p, q, r};
    }
    sort(edges.begin(), edges.end());

    for (int i=0; i<q; i++) {
        int k, v;
        cin >> k >> v;
        queries[i] = {k, v, i};
    }
    sort(queries.begin(), queries.end());

    vector<int> ans(q), s(n+1), size(n+1, 1);
    for (int i=1; i<=n; i++) {
        s[i] = i;
    }

    int edge = 0;
    for (Query query : queries) {
        int k = query.k, v = query.v, i = query.i;
        while (edge < edges.size() && edges[edge].w >= k) {
            unite(s, size, edges[edge].u, edges[edge].v);
            edge++;
        }
        ans[i] = size[find(s, v)] - 1;
    }

    for (int a : ans) {
        cout << a << "\n";
    }

    return 0;
}