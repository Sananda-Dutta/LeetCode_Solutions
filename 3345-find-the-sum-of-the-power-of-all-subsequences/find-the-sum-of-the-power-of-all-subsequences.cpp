class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = k; j >= 0; j--) {
                dp[j] = (2 * dp[j]) % MOD;
                if (j >= x) {
                    dp[j] = (dp[j] + dp[j-x]) % MOD;
                }
            }
        }

        return dp[k];
    }
};