#include <bits/stdc++.h>

using namespace std;

struct Coord {
    int x, y;
};

struct Cell {
    bool cow = false;
    vector<Coord> roads;
};

vector<vector<int> > combination(int N) {
    int K = 2;
    vector<vector<int> > result;
    std::string bitmask(K, 1);
    bitmask.resize(N, 0);
    do {
        vector<int> cur;
        for (int i = 0; i < N; ++i) {
            if (bitmask[i]) {
                cur.push_back(i);
            }
        }
        result.push_back(cur);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return result;
}

bool isRoad(vector<Coord> &roads, int x, int y) {
    for (Coord c : roads) {
        if (c.x == x && c.y == y) return true;
    }
    return false;
}

int main() {
    freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
    
    int n, k, r;
    cin >> n >> k >> r;

    vector<vector<Cell> > grid(n+2, vector<Cell>(n+2));

    vector<Coord> roads(r);
    for (int i=0; i<r; i++) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        grid[x][y].roads.push_back({xx, yy});
        grid[xx][yy].roads.push_back({x, y});
    }

    vector<Coord> cows(k);
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y].cow = true;
        cows[i] = {x, y};
    }

    vector<vector<int> > visited(n+2, vector<int>(n+2));
    int colour = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (grid[i][j].cow) {
                queue<Coord> q;
                q.push({i, j});

                int count = 0;
                while (!q.empty()) {
                    Coord cur = q.front();
                    q.pop();

                    int x = cur.x, y = cur.y;
                    if (visited[x][y] != 0) continue;
                    visited[x][y] = colour;

                    Cell cell = grid[x][y];

                    if (x-1 > 0 && !isRoad(cell.roads, x-1, y)) {
                        q.push({x-1, y});
                    }
                    if (x+1 <= n && !isRoad(cell.roads, x+1, y)) {
                        q.push({x+1, y});
                    }
                    if (y-1 > 0 && !isRoad(cell.roads, x, y-1)) {
                        q.push({x, y-1});
                    }
                    if (y+1 <= n && !isRoad(cell.roads, x, y+1)) {
                        q.push({x, y+1});
                    }
                }
                colour++;
            }
        }
    }

    int ans = 0;
    vector<vector<int> > combinations = combination(3);
    for (vector<int> x : combinations) {
        Coord a = cows[x[0]], b = cows[x[1]];
        if (visited[a.x][a.y] != visited[b.x][b.y]) ans++;
    }

    cout << ans;
    
    return 0;
}