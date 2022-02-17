#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int a = 0;
    vector<int> array(s.length(), 0);

    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'A') {
            a++;
        } else {
            array[i] = 1;
        }
    }

    int left = 0, right = a-1;
    int count = 0;
    for (int i=0; i<=right; i++) {
        count += array[i];
    }
    int ans = count;
    while (left < s.length()) {
        count -= array[left];
        right++;
        count += array[right % s.length()];
        left++;
        ans = min(ans, count);
    }

    cout << ans;

    return 0;
}