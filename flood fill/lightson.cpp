#include <bits/stdc++.h>

using namespace std;

struct Coord {
    bool on = false;
    bool visited = false;
    vector<pair<int, int> > switches;
};

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<Coord> > grid(n+2, vector<Coord>(n+2));

    for (int i=1; i<=m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        grid[x][y].switches.push_back({a, b});
    }

    queue<pair<int, int> > q;
    q.push({1, 1});
    grid[1][1].on = true;

    int ans = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first, y = cur.second;
        if (grid[x][y].visited) continue;
        grid[x][y].visited = true;

        for (const auto &c : grid[x][y].switches) {
            int xx = c.first, yy = c.second;
            if (!grid[xx][yy].on) {
                ans++;
            } else {
                continue;
            }
            grid[xx][yy].on = true;
            if (grid[xx-1][yy].visited) {
                q.push({xx, yy});
            } else if (grid[xx+1][yy].visited) {
                q.push({xx, yy});
            } else if (grid[xx][yy-1].visited) {
                q.push({xx, yy});
            } else if (grid[xx][yy+1].visited) {
                q.push({xx, yy});
            }
        }

        if (grid[x-1][y].on && !grid[x-1][y].visited) {
            q.push({x-1, y});
        }
        if (grid[x+1][y].on && !grid[x+1][y].visited) {
            q.push({x+1, y});
        }
        if (grid[x][y-1].on && !grid[x][y-1].visited) {
            q.push({x, y-1});
        }
        if (grid[x][y+1].on && !grid[x][y+1].visited) {
            q.push({x, y+1});
        }
    }

    cout << ans;

    return 0;
}