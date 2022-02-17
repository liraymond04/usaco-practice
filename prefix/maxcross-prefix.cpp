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

    int left = 1, right = k;
    int count = 0;
    for (int i=left; i<=right; i++) {
        count += cross[i];
    }
    int ans = count;
    while (left < n && right < n) {
        count -= cross[left];
        right++;
        count += cross[right];
        left++;
        ans = min(ans, count);
    }

    cout << ans;

    return 0;
}