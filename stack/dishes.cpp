#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);

    int n;
    cin >> n;

    vector<stack<int> > dirty;
    stack<int> clean;

    vector<int> b;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;

        if (!clean.empty() && num < clean.top()) {
            cout << i;
            return 0;
        }
        
        vector<int>::iterator lo = lower_bound(b.begin(), b.end(), num);
        if (lo == b.end()) {
            stack<int> st;
            st.push(num);
            b.push_back(num);
            dirty.push_back(st);
        } else {
            int index = lo-b.begin();

            while (!dirty[index].empty() && num > dirty[index].top()) {
                clean.push(dirty[index].top());
                dirty[index].pop();
            }
            dirty[index].push(num);
        }
    }

    cout << n;

    return 0;
}