#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> snakes(n), prefix;
    for (int i=0; i<n; i++) {
        cin >> snakes[i];
        if (i == 0) {
            prefix.push_back(snakes[i]);
        } else {
            prefix.push_back(prefix[i-1] + snakes[i]);
        }
    }

    vector<vector<int> > dp(n, vector<int>(k+1, INT_MAX));
    for (int i=0; i<n; i++) {
        dp[i][0] = 0;
    }

    int cur_max = INT_MIN;
    for (int i=0; i<n; i++) {
        cur_max = max(cur_max, snakes[i]);
        for (int j=0; j<=i; j++) {
            dp[i][0] += cur_max - snakes[j];
        }
    }

    int ans = dp[n-1][0];
    for (int j=1; j<=k; j++) {
        for (int i=1; i<n; i++) {
            cur_max = INT_MIN;
            for (int prev=i; prev>=j; prev--) {
                cur_max = max(cur_max, snakes[prev]);
                dp[i][j] = min(dp[i][j], dp[prev-1][j-1] + (i - prev + 1) * cur_max - (prefix[i] - prefix[prev-1]));
            }
        }
        ans = min(ans, dp[n-1][j]);
    }
    
    cout << ans;

    return 0;
}