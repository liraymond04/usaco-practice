#include <bits/stdc++.h>

using namespace std;

bool f(vector<int> &pos, int k, int x) {
    int d = x * 2;
    // 1 3 8 10 18 20 25
    int start = 0, end = 0;
    while (end < pos.size()) {
        if (pos[end] <= pos[start] + d) {
            end++;
        } else {
            start = end;
            k--;
            if (k == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> pos(n);
    for (int i=0; i<n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());

    int lo = 0, hi = (pos[pos.size()-1] - pos[0]) / 2;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(pos, k, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;

    return 0;
}