#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string first , second , last;
        for(char ch:s){
            if(ch==y){
                first+=ch;
            }
            else if(ch !=x && ch !=y){
                second+=ch;
            }
            else{
                last+=ch;
            }
        }
        return first+second+last;
    }
};