#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
    int dp[10001];
    int solve(int i, vector<int>& heights) {
        int n = heights.size();
        if (i == n - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int option1 = INT_MAX;
        int option2 = INT_MAX;
        if (i + 1 < n)
            option1 = abs(heights[i] - heights[i + 1]) + solve(i + 1, heights);
        if (i + 2 < n)
            option2 = abs(heights[i] - heights[i + 2]) + solve(i + 2, heights);
        return dp[i] = min(option1, option2);
    }
    int frogJump(vector<int>& heights) {
        memset(dp, -1, sizeof(dp));
        return solve(0, heights);
    }
};