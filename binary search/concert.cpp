#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// calculate minimum time spent
// save and update min
// pass min into binary search

struct Friend {
    int p, w, d;
};

ll dist(vector<Friend> &friends, Friend &f, int x) {
    if (f.p == x) return 0;
    if (f.p < x) {
        int d = f.p + f.d;
        if (x - d <= 0) return 0;
        return (ll)(x - d) * f.w;
    } else {
        int d = f.p - f.d;
        if (d - x <= 0) return 0;
        return (ll)(d - x) * f.w;
    }
}

bool f(vector<Friend> &friends, int x, ll &m) {
    ll d = 0;
    for (auto &f : friends) {
        d += dist(friends, f, x);
    }
    if (d <= m) {
        m = d;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int lo = INT_MAX, hi = 0;
    vector<Friend> friends(n);
    for (int i=0; i<n; i++) {
        int p, w, d;
        cin >> p >> w >> d;
        lo = min(lo, p);
        hi = max(hi, p);
        friends[i] = {p, w, d};
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    ll m = LONG_LONG_MAX;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(friends, mid, m)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << m;

    return 0;
}