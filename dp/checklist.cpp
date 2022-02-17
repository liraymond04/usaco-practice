#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Pos {
    ll x, y;
};

ll dist(Pos a, Pos b) {
    ll deltax = a.x - b.x, deltay = a.y - b.y;
    return deltax * deltax + deltay * deltay;
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int h, g;
    cin >> h >> g;

    vector<Pos> hol(h+1), gue(g+1);
    for (int i=1; i<=h; i++) {
        cin >> hol[i].x >> hol[i].y;
    }
    for (int i=1; i<=g; i++) {
        cin >> gue[i].x >> gue[i].y;
    }

    // 0 - H, 1 - G
    vector<vector<vector<ll> > > dp(h+1, vector<vector<ll> >(g+1, vector<ll>(2, (ll)2 * 999 * 999 * 2000)));

    hol[0] = hol[1];
    dp[0][0][0] = 0;
    for (int i=1; i<=h; i++) {
        dp[i][0][0] = dp[i-1][0][0] + dist(hol[i], hol[i-1]);
    }
    
    gue[0] = gue[1];
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=g; j++) {
            vector<ll> left = dp[i][j-1], top = dp[i-1][j];
            dp[i][j][0] = min(top[0] + dist(hol[i], hol[i-1]), top[1] + dist(hol[i], gue[j]));
            dp[i][j][1] = min(left[0] + dist(gue[j], hol[i]), left[1] + dist(gue[j], gue[j-1]));
        }
    }

    cout << dp[h][g][0];
    
    return 0;
}