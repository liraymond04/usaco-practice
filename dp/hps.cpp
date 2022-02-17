#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<char> fj(n); 
    for (int i=0; i<n; i++) {
        cin >> fj[i];
    }
    
    // 0 - H, 1 - P, 2 - S
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(k+1, vector<int>(3)));

    for (int i=1; i<=n; i++) {
        dp[i][0][0] = dp[i-1][0][0] + (fj[i-1] == 'S' ? 1 : 0);
        dp[i][0][1] = dp[i-1][0][1] + (fj[i-1] == 'H' ? 1 : 0);
        dp[i][0][2] = dp[i-1][0][2] + (fj[i-1] == 'P' ? 1 : 0);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            vector<int> d = dp[i-1][j-1], v = dp[i-1][j];
            dp[i][j][0] = max(v[0], max(d[1], d[2])) + (fj[i-1] == 'S' ? 1 : 0);
            dp[i][j][1] = max(v[1], max(d[0], d[2])) + (fj[i-1] == 'H' ? 1 : 0);
            dp[i][j][2] = max(v[2], max(d[1], d[0])) + (fj[i-1] == 'P' ? 1 : 0);
        }
    }

    int ans = 0;
    for (int i=0; i<3; i++) {
        ans = max(ans, dp[n][k][i]);
    }

    cout << ans;

    return 0;
}