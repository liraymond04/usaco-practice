#include <bits/stdc++.h>

using namespace std;

bool f(int x) {
    if (x < 50) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int lo = 0, hi = 100;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;

    return 0;
}