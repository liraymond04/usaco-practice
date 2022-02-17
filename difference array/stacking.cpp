#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> seq(n+2, 0);
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        seq[a]++;
        seq[b+1]--;
    }

    for (int i=1; i<=n; i++) {
        seq[i] = seq[i] + seq[i-1];
    }
    sort(seq.begin(), seq.end());

    cout << seq[n/2 + 1];

    return 0;
}