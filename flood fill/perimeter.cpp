#include <bits/stdc++.h>

using namespace std;

pair<int, int> bfs(vector<vector<char> > &grid, vector<vector<bool> > &visited, int i, int j, int n) {
    queue<pair<int, int> > q;
    q.push({i, j});

    int area = 0, perimeter = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first, y = cur.second;
        if (visited[x][y]) continue;
        
        visited[x][y] = true;
        area++;

        int add = 4;
        if (grid[x-1][y] == '#') {
            add--;
        }
        if (grid[x+1][y] == '#') {
            add--;
        }
        if (grid[x][y-1] == '#') {
            add--;
        }
        if (grid[x][y+1] == '#') {
            add--;
        }

        if (!visited[x-1][y] && grid[x-1][y] == '#') {
            q.push({x-1, y});
        }
        if (!visited[x+1][y] && grid[x+1][y] == '#') {
            q.push({x+1, y});
        }
        if (!visited[x][y-1] && grid[x][y-1] == '#') {
            q.push({x, y-1});
        }
        if (!visited[x][y+1] && grid[x][y+1] == '#') {
            q.push({x, y+1});
        }

        perimeter += add;
    }

    return {area, perimeter};
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<char> > grid(n + 2, vector<char>(n + 2));
    vector<vector<bool> > visited(n + 2, vector<bool>(n + 2, false));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> grid[i][j];
        }
    }

    int area = 0, perimeter = INT_MAX;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!visited[i][j] && grid[i][j] == '#') {
                pair<int, int> t = bfs(grid, visited, i, j, n);
                if (t.first > area) {
                    area = t.first;
                    perimeter = t.second;
                } else if (t.first == area) {
                    perimeter = min(perimeter, t.second);
                }
            }
        }
    }

    cout << area << " " << perimeter;
    
    return 0;
}