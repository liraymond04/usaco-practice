#include <bits/stdc++.h>

using namespace std;

/*
You are given n balloons, indexed from 0 to n - 1.
Each balloon is painted with a number on it represented by an array nums.
You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a
balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.



Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10

 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    
    vector<vector<int> > dp(n+2, vector<int>(n+2));
    
    dp[0][0] = 1;
    dp[n+1][n+1] = 1;
    for (int i=1; i<=n; i++) {
        dp[i][i] = nums[i-1];
    }
    
    for (int len=0; len<n; len++) {
        for (int i=1; i<=n; i++) {
            int j = i + len;
            
            dp[i][j] = max(dp[i][j], nums[i-1] * nums[i] * nums[j]);
            dp[i][j] = max(dp[i][j], nums[i] * nums[j] * nums[j+1]);
            for (int k=i+1; k<j; k++) {
                dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j]);
            }
        }
    }
    
    return dp[0][n];
}