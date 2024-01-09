204. Count Primes

Problem Link: https://leetcode.com/problems/count-primes/description/

Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 10^6


//Code:

class Solution {
public:
     int countPrimes(int n) {
         if(n<=1){
             return 0;
         }
        vector<bool>is_prime(n,1);
        is_prime[0] = is_prime[1] = false;
        for(int i=2;i<n;i++){
            if(is_prime[i]==true){
                for(int j=2*i;j<n;j+=i){
                    is_prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(is_prime[i]==true){
                cnt++;
            }
        }
        return cnt;
    }   
};