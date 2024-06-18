class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        vector<int> row(n+1, 0), curr(n+1);
        for (int ind = n-1; ind>=0; ind--){
            for (int prev = -1; prev < ind; prev++){
                if (prev == -1 || nums[ind] > nums[prev]){
                    int pick = 1 + row[ind+1]; 
                    int notpick = row[prev+1]; 
                    curr[prev+1] = max(pick, notpick);
                }
                else {
                    curr[prev+1] = row[prev+1]; 
                }
            }
            row = curr;
        }
        return row[0];
    }
};