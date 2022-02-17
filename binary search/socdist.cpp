
#include <bits/stdc++.h>

using namespace std;

bool f(vector<pair<int, int> > &intervals, int n, int m, long long d) {
    long long pos = intervals[0].first;
    
    int cur = 0;
    for (int i = 1; i < n; i++) {
        pos += d;
        while (cur < m && pos > intervals[cur].second) {
            cur++;
        }
        if (cur == m) {
            return false;
        }
        if (intervals[cur].first > pos) {
            pos = intervals[cur].first;
        }
    }
    return true;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > intervals(m);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        intervals[i].first = a;
        intervals[i].second = b;
    }
    sort(intervals.begin(), intervals.end());

    long long lo = 0, hi = pow(10, 18) + 5;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (f(intervals, n, m, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo;
    
    return 0;
}