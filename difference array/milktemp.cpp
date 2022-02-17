#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("milktemp.in", "r", stdin);
    freopen("milktemp.out", "w", stdout);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    map<int, int> range;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        range[a] += y - x; range[b+1] += z - y;
    }

    int cur = n * x;
    int ans = cur;
    for (const auto &x : range) {
        cur = cur + x.second;
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}