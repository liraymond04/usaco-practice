#include <bits/stdc++.h>

using namespace std;


bool f(vector<int> &cows, int m, int c, int x) {
    int i = 1, cap = 1;
    int first = cows[0];
    while (i < cows.size()) {
        int dif = cows[i] - first;
        if (dif <= x && cap != c) {
            cap++;
        } else {
            first = cows[i];
            cap = 1;
            m--;
            if (m <= 0) {
                return false;
            }
        }
        i++;
    }
    if (m <= 0) {
        return false;
    }
    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    
    int n, m, c;
    cin >> n >> m >> c;
    
    vector<int> cows(n);
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    int lo = 0, hi = cows[n-1] - cows[0];
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(cows, m, c, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;

    return 0;
}