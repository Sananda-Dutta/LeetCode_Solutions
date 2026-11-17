class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute costs for every substring
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                cost[i][j] = INT_MAX;

                // Find valid divisors of substring length
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Compare symmetric characters
                    // in each of the d groups
                    for (int x = 0; x < d; x++) {

                        int left = i + x;
                        int right = i + x + (len / d - 1) * d;

                        while (left < right) {

                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // DP
        // dp[i][parts] = minimum changes to divide
        // first i characters into exactly parts substrings

        vector<vector<int>> dp(n + 1,vector<int>(k + 1, INT_MAX / 2));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 1; i <= n; i++) {

                // Last substring length must be >= 2
                for (int len = 2; len <= i; len++) {

                    int j = i - len;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[j][parts - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};