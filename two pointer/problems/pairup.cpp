#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int num, output;
    friend bool operator < (Cow &l, Cow &r) {
        return l.output < r.output;
    }
};

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;

    vector<Cow> cows;
    for (int i=0; i<n; i++) {
        int m, y;
        cin >> m >> y;
        cows.push_back({m, y});
    }
    sort(cows.begin(), cows.end());
    
    int left = 0, right = cows.size() - 1;
    int ans = 0;
    while (left < right) {
        if (cows[left].num > 0 && cows[right].num > 0) {
            int sum = cows[left].output + cows[right].output;
            ans = max(ans, sum);
            int sub = min(cows[left].num, cows[right].num);
            cows[left].num -= sub; cows[right].num -= sub;
        } else {
            if (cows[left].num == 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << ans << "\n";

    // https://leetcode.com/problems/two-sum/

    return 0;
}