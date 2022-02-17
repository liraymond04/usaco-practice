#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, b;
    cin >> n >> k >> b;

    vector<int> cross(n+1, 0);

    for (int i=0; i<b; i++) {
        int num;
        cin >> num;
        cross[num] = 1;
    }

    vector<int> prefix(n+1);
    partial_sum(cross.begin(), cross.end(), prefix.begin());

    int ans = INT_MAX;
    for (int i=0; i+k<n; i++) {
        ans = min(ans, prefix[i+k] - prefix[i]);
    }

    cout << ans;

    return 0;
}