#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b;
    cin >> t >> a >> b;

    vector<bool> dp(t+1, false);
    vector<bool> water(t+1, false);

    int ans = 0;

    dp[0] = true;
    for (int i=0; i<=t; i++) {
        if (dp[i]) {
            ans = max(ans, i);
            if (i + a <= t) {
                dp[i + a] = true;
            }
            if (i + b <= t) {
                dp[i + b] = true;
            }
            water[i / 2] = true;
        }
    }
    for (int i=1; i<=t; i++) {
        if (water[i]) {
            ans = max(ans, i);
            if (i + a <= t) {
                water[i + a] = true;
            }
            if (i + b <= t) {
                water[i + b] = true;
            }
        }
    }

    cout << ans;
    
    return 0;
}