#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
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
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int>t(n,1);
        int maxl=1;
        for(int i= 0 ; i< n ; i++){
            for(int j=0 ; j < i ; j++){
                if(ispredecessor(words[i],words[j])){
                    t[i]=max(t[i],t[j]+1);
                    maxl=max(maxl,t[i]);
                }
            }
        }
        return maxl;
    }
};