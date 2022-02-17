#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);

    string s;
    cin >> s;

    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }

    int ans = 0;
    while (!st.empty()) {
        char right = st.top();
        st.pop();
        char left = st.top();
        st.pop();

        if (right == left) {
            ans++;
        } else {
            ans += 2;
        }
    }

    cout << ans;

    return 0;
}