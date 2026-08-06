#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int dp[1000][1000];
    int solve(int idx, int prevIdx, vector<int>& nums) {
        if (idx == nums.size())return 0;
        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];
        // Not take
        int notTake = solve(idx + 1, prevIdx, nums);
        // Take
        int take = 0;
        if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0) {
            take = 1 + solve(idx + 1, idx, nums);
        }
        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        solve(0, -1, nums);
        // Reconstruct the answer
        vector<int> ans;
        int idx = 0, prevIdx = -1;
        while (idx < nums.size()) {
            int notTake = solve(idx + 1, prevIdx, nums);
            int take = -1;
            if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0) {
                take = 1 + solve(idx + 1, idx, nums);
            }
            if (take >= notTake) {
                ans.push_back(nums[idx]);
                prevIdx = idx;
            }
            idx++;
        }
        return ans;
    }
};