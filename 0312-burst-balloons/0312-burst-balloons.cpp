class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-2; i >= 1; i--){
            for (int j = i; j <= n-2; j++){
                int ans = 0;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1];
                    coins += dp[i][k-1]; // f(i, k - 1, nums, dp);
                    coins += dp[k+1][j]; // f(k + 1, j, nums, dp);
                    ans = max(ans, coins);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n-2]; // f(1, n - 2, nums, dp);
    }
};