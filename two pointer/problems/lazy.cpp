#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int> > field(n);
    for (int i=0; i<n; i++) {
        cin >> field[i].second >> field[i].first;
    }
    sort(field.begin(), field.end());

    int sum = 0, ans = 0;
    int left = 0, right = 0;
    while (left < n || right < n) {
        int range = field[right].first - field[left].first;
        while (range <= 2 * k && right < n) {
            sum += field[right].second;
            right++;
            range = field[right].first - field[left].first;
        }
        ans = max(ans, sum);

        sum -= field[left].second;
        left++;
    }

    cout << ans << "\n";

    return 0;
}