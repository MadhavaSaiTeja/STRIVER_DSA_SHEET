/*
1922. Count Good Numbers
Problem Link : https://leetcode.com/problems/count-good-numbers/description/
*/

//A simple binary exponentiation can be used to solve this problem...

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9+7;
        long long x = n / 2,y = n - x;
        long long f4 = 4,f5=5;
        long long xx = x,yy=y; long long a1 = 1,a2 = 1;
        while(xx > 0){
            if(xx%2){
                xx--;
                a1 = (a1 * f4) % mod;
            }
            else{
                f4 = (f4 * f4) % mod;
                xx /= 2;
            }
        }
        while(yy > 0){
            if(yy%2){
                yy--;
                a2 = (a2 * f5) % mod;
            }
            else{
                f5 = (f5 * f5) % mod;
                yy /= 2;
            }
        }
        return (a1 * a2) % mod;
    }
};