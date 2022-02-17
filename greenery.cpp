#include <bits/stdc++.h>

using namespace std;

long long solve(vector<vector<int> > &grid, int n) {
    long long total = 0;
    for (int i=0; i<n; i++) {
        vector<bool> all_ones(n, true);
        for (int j=i; j<n; j++) {
            int ones = 0;
            for (int k=0; k<n; k++) {
                all_ones[k] = all_ones[k] & grid[j][k];
                if (all_ones[k]) {
                    ones++;
                    total += ones;
                } else {
                    ones = 0;
                }
            }
        }
    }

    return total;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > greater_eq(n, vector<int>(n, 0)), greater(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int num;
            cin >> num;

            if (num >= 100) {
                greater_eq[i][j] = 1;
            }
            if (num > 100) {
                greater[i][j] = 1;
            }
        }
    }

    long long ans = solve(greater_eq, n) - solve(greater, n);

    cout << ans << "\n";

    return 0;
}