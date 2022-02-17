#include <iostream>
#include <vector>
using namespace std;

bool subArraySum(const vector<int> &v, int x) {
    int n = v.size();
    int left = 0, right = 0;
    int sum = v[0];
    while (left < n && right < n) {
        if (sum < x) {
            right++;
            if (right == n) {
                break;
            }
            sum += v[right];
        } else if (sum > x) {
            sum -= v[left];
            left++;
        } else {
            cout << left << " " << right << "\n";
            return true;
        }
    }

    return false;
}


int main() {
    vector<int> v1 {1, 4, 20, 3, 10, 5};
    cout << subArraySum(v1, 33) << endl;
    cout << subArraySum(v1, 2) << endl;
    cout << subArraySum(v1, 34) << endl;
    vector<int> v2 {35, 1, 4, 20, 3, 10, 5};
    cout << subArraySum(v2, 33) << endl;

    return 0;
}