#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    return x*x - 2*x + 1;
}

int findBottom(int low, int high) {
    while (low < high) {
        int mid = (low + high) / 2;
        if (f(mid) > f(mid+1)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    cout << findBottom(0, 9) << endl;

    return 0;
}