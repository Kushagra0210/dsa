#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    int t[1001][1001];
    static bool cmp(const string &a,const string &b){
        return a.length() < b.length();
    }
    bool ispredecessor(string &a, string &b){
        int N=a.length();
        int M=b.length();
        if(N!=M+1) return false;
        int i=0 ;
        int j=0 ;
        while(i<M && j<N){
                 if (a[j] == b[i]) i++;                
                   j++;
              }
        return i==M;
    }
    int lis(vector<string>& words,int prev ,int curr){
        int n=words.size();
        if(curr==n) return 0;
        if(prev !=-1 && t[prev][curr]!=-1){
            return t[prev][curr];
        }
        int take=0;
        int nottake=0;
        if(prev == -1 || ispredecessor(words[curr],words[prev])){
            take=1+lis(words,curr,curr+1);
        }
        nottake=lis(words,prev,curr+1);
        if(prev!=-1) t[prev][curr]=max(take,nottake);
        return max(take,nottake);
        }
    
    int longestStrChain(vector<string>& words) {
      memset(t,-1,sizeof(t));
      sort(begin(words),end(words),cmp);
      return lis(words,-1,0);
    }
};