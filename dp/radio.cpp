#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int x, y;
};

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    Pos cur_j, cur_b;
    cin >> cur_j.x >> cur_j.y;
    cin >> cur_b.x >> cur_b.y;

    string s_j, s_b;
    cin >> s_j;
    cin >> s_b;

    vector<Pos> john(n+1), bessie(m+1);
    john[0] = cur_j; bessie[0] = cur_b;
    for (int i=1; i<=n; i++) {
        if (s_j[i-1] == 'N') {
            john[i] = { john[i-1].x, john[i-1].y + 1 };
        } else if (s_j[i-1] == 'S') {
            john[i] = { john[i-1].x, john[i-1].y - 1 };
        } else if (s_j[i-1] == 'E') {
            john[i] = { john[i-1].x + 1, john[i-1].y };
        } else {
            john[i] = { john[i-1].x - 1, john[i-1].y };
        }
    }
    for (int i=1; i<=m; i++) {
        if (s_b[i-1] == 'N') {
            bessie[i] = { bessie[i-1].x, bessie[i-1].y + 1 };
        } else if (s_b[i-1] == 'S') {
            bessie[i] = { bessie[i-1].x, bessie[i-1].y - 1 };
        } else if (s_b[i-1] == 'E') {
            bessie[i] = { bessie[i-1].x + 1, bessie[i-1].y };
        } else {
            bessie[i] = { bessie[i-1].x - 1, bessie[i-1].y };
        }
    }

    vector<vector<int> > dp(n+1, vector<int>(m+1));

    for (int i=1; i<=n; i++) {
        int deltax = john[i].x - bessie[0].x, deltay = john[i].y - bessie[0].y;
        dp[i][0] = dp[i-1][0] + (deltax * deltax) + (deltay * deltay);
    }
    for (int i=1; i<=m; i++) {
        int deltax = john[0].x - bessie[i].x, deltay = john[0].y - bessie[i].y;
        dp[0][i] = dp[0][i-1] + (deltax * deltax) + (deltay * deltay);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int deltax = john[i].x - bessie[j].x, deltay = john[i].y - bessie[j].y;
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + (deltax * deltax) + (deltay * deltay);
        }
    }

    cout << dp[n][m];
    
    return 0;
}