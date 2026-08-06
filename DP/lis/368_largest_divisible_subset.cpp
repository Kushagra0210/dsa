#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    vector<int>ans;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>t(n,1);
        vector<int>prev_idx(n,-1);
        int last_chosen=0;
        int maxl=1;
        for(int i= 0 ; i<nums.size() ; i++){
            for(int j=0 ; j<i ;j++){
                 if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                    t[i]=t[j]+1;
                    prev_idx[i]=j;
                 }
                if(t[i]>maxl){
                    maxl=t[i];
                    last_chosen=i;
                }
                }
            }
        }
        while(last_chosen !=-1){
            ans.push_back(nums[last_chosen]);
            last_chosen=prev_idx[last_chosen];
        }
        return ans;
    }
};