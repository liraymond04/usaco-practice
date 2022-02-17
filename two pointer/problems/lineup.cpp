#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;

    unordered_map<int, int> nums;
    vector<pair<int, int> > lineup(n);
    for (int i=0; i<n; i++) {
        cin >> lineup[i].first >> lineup[i].second;
        nums[lineup[i].second] = 0;
    }
    sort(lineup.begin(), lineup.end());

    int ans = INT_MAX;
    int num_count = 0, num_size = nums.size();
    int left = 0, right = 0;
    while (left < n || right < n) {
        while (num_count < num_size && right < n) {
            int cur = lineup[right].second;
            if (nums[cur] == 0) {
                num_count++;
                if (num_count == num_size) {
                    break;
                }
            }
            nums[cur]++;
            right++;
        }

        if (right >= n) {
            break;
        }

        while (nums[lineup[left].second] > 1 && left < right) {
            nums[lineup[left].second]--;
            left++;
        }

        int size = lineup[right].first - lineup[left].first;
        ans = min(ans, size);
        num_count--;
        nums[lineup[left].second]--;
        left++; right++;
    }

    cout << ans << "\n";

    return 0;
}