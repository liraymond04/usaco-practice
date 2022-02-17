#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> diamonds(n);
    for (int i=0; i<n; i++) {
        cin >> diamonds[i];
    }
    sort(diamonds.begin(), diamonds.end());

    vector<int> indexes(n);
    int start = 0, check = 0;
    while (start != n) {
        while (check != n && diamonds[check] - diamonds[start] <= k) {
            check++;
        }
        indexes[start] = check-1;
        start++;
    }

    int start1 = 0;
    int ans = 0;
    int prev = 0;
    int case2 = 0;
    while (start1 != n) {
        int end1 = indexes[start1];
        if (end1 > prev) {
            int start2 = end1 + 1;
            prev = start2-1;
            case2 = 0;
            while (start2 != n) {
                case2 = max(case2, indexes[start2] - start2 + 1);
                start2++;
            }
        }
        int case1 = indexes[start1] - start1 + 1;
        ans = max(ans, case1 + case2);
        start1++;
    }

    cout << ans;

    return 0;
}