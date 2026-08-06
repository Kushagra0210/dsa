#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
    int dp[10001];
    int solve(int i, vector<int>& heights, int k) {
        int n = heights.size();
        if (i == n - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;
        for (int nextJump = i + 1;
             nextJump <= i + k && nextJump < n;
             nextJump++) {
            mini = min(
                mini,
                abs(heights[nextJump] - heights[i]) +
                solve(nextJump, heights, k)
            );
        }
        return dp[i] = mini;
    }
    int frogJump(vector<int>& heights, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, heights, k);
    }
};