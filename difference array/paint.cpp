#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    map<int, int> range;
    set<int> seq;

    int location = 0;
    for (int i=0; i<n; i++) {
        int num; char c;
        cin >> num >> c;

        if (c == 'R') {
            range[location]++;
            location += num;
            range[location]--;
        } else {
            range[location]--;
            location -= num;
            range[location]++;
        }
        seq.insert(location);
    }

    int ans = 0;
    int cur = 0, i = 0;
    map<int, int>::iterator right = range.begin(), left = right++;
    while (right != range.end()) {
        cur = cur + left->second;
        if (cur >= k) {
            ans += right->first - left->first;
        }
        left++; right++;
    }

    cout << ans;

    return 0;
}