#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> seq(n);
    for (int i=0; i<n; i++) {
        cin >> seq[i];
    }

    vector<vector<int> > dp(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        dp[i][i] = seq[i];
    }

    int ans = 0;
    for (int len=1; len<n; len++) {
        for (int i=0; i<n-len; i++) {
            int j = i + len;
            for (int k=i; k<j; k++) {
                if (dp[i][k] > 0 && dp[i][k] == dp[k+1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}