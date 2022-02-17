#include <bits/stdc++.h>

using namespace std;

int sqrt(int n) {
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid > n) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return hi;
}

int main() {
    cout << sqrt(9) << "\n";
    cout << sqrt(8) << "\n";
    cout << sqrt(15) << "\n";
    cout << sqrt(16) << "\n";
    
    return 0;
}