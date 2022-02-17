#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    string result = "";
    int result_size = INT_MAX;

    unordered_map<char, int> chars;
    unordered_map<char, int> window;
    for (const char &x : t) {
        chars[x]++;
    }

    int n = s.size();
    int req = chars.size();

    int cur = 0;
    int left = 0, right = 0;
    while (right < n) {
        char c = s[right];
        window[c]++;

        if (chars.count(c) != 0 && window[c] == chars[c]) {
            cur++;
        }

        while(left <= right && cur == req) {
            char l = s[left];

            int cur_size = right - left + 1;
            if (cur_size < result_size) {
                result_size = cur_size;
                result = s.substr(left, cur_size);
            }
            window[l]--;

            if (chars.count(l) != 0 && window[l] < chars[l]) {
                cur--;
            }
            
            left++;
        }
        
        right++;
    }

    if (result_size == -1) {
        cout << "";
    } else {
        cout << result;
    }

    return 0;
}