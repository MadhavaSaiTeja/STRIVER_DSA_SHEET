/*
860. Lemonade Change
Problem Link : https://leetcode.com/problems/lemonade-change/description/
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0,tens = 0;
        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                fives++;
            }
            if(bills[i] == 10){
                tens++;
                if(fives >= 1){
                    fives--;
                }
                else{
                    return false;
                }
            }
            if(bills[i] == 20){
                if(tens >= 1){
                    if(fives >= 1){
                        tens--; fives--;
                    }
                    else{
                        return false;
                    }
                }
                else if(fives >= 3){
                    fives -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
