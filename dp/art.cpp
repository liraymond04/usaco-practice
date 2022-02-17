#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    vector<vector<int> > dp(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        dp[i][i] = 1;
    }

    for (int len=1; len<n; len++) {
        for (int i=0; i<n-len; i++) {
            int j = i + len;
            
            if (v[i] == v[j]) {
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
            } else {
                int m = INT_MAX;
                for (int k=i; k<j; k++) {
                    m = min(m, dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = m;
            }
        }
    }

    cout << dp[0][n-1];
    
    return 0;
}