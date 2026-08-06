#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(
                dp[i - 1] + abs(heights[i] - heights[i - 1]),
                (i > 1)
                    ? dp[i - 2] + abs(heights[i] - heights[i - 2])
                    : INT_MAX
            );
        }
        return dp[n - 1];
    }
};