#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> h(n+1, 0), p(n+1, 0), s(n+1, 0);
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        h[i] = h[i-1];
        p[i] = p[i-1];
        s[i] = s[i-1];
        if (c == 'H') {
            p[i] = p[i-1] + 1;
        } else if (c == 'P') {
            s[i] = s[i-1] + 1;
        } else if (c == 'S') {
            h[i] = h[i-1] + 1;
        }
    }

    int ans = 0;

    // h -> p, h -> s
    // p -> h, p -> s
    // s -> h, s -> p
    for (int i=1; i<=n; i++) {
        int htp = h[i-1] + (p[n] - p[i-1]);
        int hts = h[i-1] + (s[n] - s[i-1]);
        int pth = p[i-1] + (h[n] - h[i-1]);
        int pts = p[i-1] + (s[n] - s[i-1]);
        int sth = s[i-1] + (h[n] - h[i-1]);
        int stp = s[i-1] + (p[n] - p[i-1]);
        ans = max(ans, max(htp, max(hts, max(pth, max(pts, max(sth, stp))))));
    }

    cout << ans;

    return 0;
}