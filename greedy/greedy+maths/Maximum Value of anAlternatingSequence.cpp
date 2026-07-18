class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // Peak Valley Peak Valley ...
        // Valley Peak Valley Peak ...
    // n is even 2 4 6 
    // max -->last index
    // n is odd
    // max-->2 last index
    // n= 1 2 3 4 5 6 
    // 1 subtraction which is : 0 0 1 1 2 2 ...
    // n=4 s=3 m=5 3 +5 -1 +5
    if(n==1) return s;
    long long noofincreases=n/2;
    long long noofdecreases=noofincreases-1;
    return 0ll+ s+noofincreases*m-noofdecreases;
    } 
};