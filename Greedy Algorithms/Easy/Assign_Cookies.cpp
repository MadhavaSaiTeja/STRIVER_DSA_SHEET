/*
455.Assign Cookies
Problem link : https://leetcode.com/problems/assign-cookies/
*/

class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& s) {
        int n1 = greed.size(),n2 = s.size();
        sort(greed.begin(),greed.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int j = 0;
        for(int i=0;i<n1;i++){
            while(j < n2 and greed[i] > s[j]){
                j++;
            }
            if(j < n2 and s[j] >= greed[i]){
                ans++;
                j++;
            }
        }
       return ans;
    }
};