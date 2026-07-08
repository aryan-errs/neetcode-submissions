class Solution {
public:
    int helper(vector<int>& dp, vector<int>& coins, int amount, int cnt){
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != 1e9) return dp[amount];
        for(int i = 0; i < coins.size(); i++){
            if(amount - coins[i] >= 0)
                dp[amount] = min(dp[amount], 1+helper(dp, coins, amount-coins[i], cnt+1));
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        int ans = helper(dp,coins, amount, 0);
        return ans == 1e9? -1 : ans;
    }
};
