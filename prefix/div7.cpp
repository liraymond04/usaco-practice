#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    vector<long long> prefix(n+1, 0);
    for (int i=1; i<=n; i++) {
        int num;
        cin >> num;
        prefix[i] = prefix[i-1] + num;
    }
    
    int ans = 0;
    for (int i=0; i<7; i++) {
        int left = -1, right = -1;
        for (int j=1; j<=n; j++) {
            if (prefix[j] % 7 == i) {
                if (left == -1) {
                    left = j;
                } else {
                    right = j;
                }
            }
        }
        if (right != -1) {
            ans = max(ans, right - left);
        }
    }

    cout << ans;

    return 0;
}