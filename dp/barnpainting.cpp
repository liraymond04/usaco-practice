#include <bits/stdc++.h>

using namespace std;

#define N 1000000007

long long solve(vector<vector<int> > &dp, vector<vector<int> > &adj, vector<int> &fixed, int barn, int colour, int parent) {
    if (dp[barn][colour] != 0) return dp[barn][colour];
    if (fixed[barn] > 0 && fixed[barn] != colour) return 0;

    long long ans = 1;
    for (auto b : adj[barn]) {
        if (fixed[b] == colour) return 0;
        if (b == parent) continue;
        long long total = 0;
        for (int i=1; i<=3; i++) {
            if (i == colour) continue;
            total += solve(dp, adj, fixed, b, i, barn);
            total = total % N;
        }
        ans *= total;
        ans = ans % N;
    }

    dp[barn][colour] = ans;
    return ans;
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<vector<int> > dp(n+1, vector<int>(4, 0));

    vector<vector<int> > adj(n+1);
    vector<int> fixed(n+1);

    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i=0; i<k; i++) {
        int b, c;
        cin >> b >> c;
        fixed[b] = c;
    }

    long long ans = (solve(dp, adj, fixed, 1, 1, -1) + solve(dp, adj, fixed, 1, 2, -1) + solve(dp, adj, fixed, 1, 3, -1)) % N;
    cout << ans;
    
    return 0;
}