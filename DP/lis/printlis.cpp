#include <bits/stdc++.h>
using namespace std;
vector<int> printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,1);
    vector<int>prev_idx(n,-1);
    int maxl=0;
    int last_chosen=0;
    for(int i=0 ; i<n ; i++){
        for(int j =0 ; j<i ;j++){
            if(nums[i]>nums[j]){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev_idx[i]=j;
                }
                if(dp[i]>maxl){
                    maxl=dp[i];
                    last_chosen=i;
                }
            }
        }
    }
    vector<int> ans;
    while (last_chosen != -1)
    {
        ans.push_back(nums[last_chosen]);
        last_chosen=prev_idx[last_chosen];
    }   
    return ans;
}
int main() {
    vector<int> nums = {5, 4, 11, 1, 16, 8};
    vector<int> ans = printLIS(nums);
    cout << "LIS: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}