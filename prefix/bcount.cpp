#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> ones(n+1, 0), twos(n+1, 0), threes(n+1, 0);
    for (int i=1; i<=n; i++) {
        int num;
        cin >> num;
        ones[i] = ones[i-1];
        twos[i] = twos[i-1];
        threes[i] = threes[i-1];
        if (num == 1) {
            ones[i]++;
        } else if (num == 2) {
            twos[i]++;
        } else if (num == 3) {
            threes[i]++;
        }
    }

    for (int i=0; i<q; i++) {
        int f, t;
        cin >> f >> t;
        cout << ones[t] - ones[f-1] << " " << twos[t] - twos[f-1] << " " << threes[t] - threes[f-1] << "\n";
    }

    return 0;
}