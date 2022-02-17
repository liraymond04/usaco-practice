#include <bits/stdc++.h>

using namespace std;

bool f(vector<int> &cows, int t, int x) {
    priority_queue<int, vector<int>, greater<int> > q;

    for (int c : cows) {
        if (q.size() < x) {
            q.push(c);
        } else {
            int front = q.top();
            q.pop();
            q.push(c + front);
            if (c + front > t) {
                return false;
            }
        }
    }

    while (!q.empty()) {
        int front = q.top();
        q.pop();
        if (front > t) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    
    int n, t;
    cin >> n >> t;
    
    vector<int> cows(n);
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(cows, t, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;

    return 0;
}