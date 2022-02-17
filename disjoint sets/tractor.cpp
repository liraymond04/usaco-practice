#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    friend bool operator < (const Edge& l, const Edge& r) {
       return l.w < r.w;
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

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    int n;
    cin >> n;

    int N = n * n;

    vector<vector<int> > grid(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<Edge> edges;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int cur = i * n + j;
            int top = (i-1) * n + j, bottom = (i+1) * n + j, left = i * n + (j-1), right = i * n + (j+1);

            if (i > 0) {
                edges.push_back({cur, top, abs(grid[i][j] - grid[i-1][j])});
            }
            if (i < n - 1) {
                edges.push_back({cur, bottom, abs(grid[i][j] - grid[i+1][j])});
            }
            if (j > 0) {
                edges.push_back({cur, left, abs(grid[i][j] - grid[i][j-1])});
            }
            if (j < n - 1) {
                edges.push_back({cur, right, abs(grid[i][j] - grid[i][j+1])});
            }
        }
    }
    sort(edges.begin(), edges.end());

    vector<int> s(N), size(N, 1);

    for (int i=0; i<N; i++) {
        s[i] = i;
    }

    int ans;

    int half;
    if (N & 1) {
        half = N/2 + 1;
    } else {
        half = N/2;
    }

    for (Edge edge : edges) {
        int x = edge.u, y = edge.v;
        int px = find(s, x), py = find(s, y);

        if (px == py) {
            continue;
        } else {
            if (size[px] < size[py]) {
                s[px] = py;
                size[py] += size[px];
                if (size[py] >= half) {
                    ans = edge.w;
                    break;
                }
            } else {
                s[py] = px;
                size[px] += size[py];
                if (size[px] >= half) {
                    ans = edge.w;
                    break;
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}