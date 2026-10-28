
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1) return false;

        vector<unordered_set<int>> dp(n);

        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int k : dp[i]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump <= 0) continue;

                    int target = stones[i] + jump;

                    auto it = lower_bound(
                        stones.begin(), stones.end(), target
                    );

                    if (it != stones.end() && *it == target) {
                        int j = it - stones.begin();
                        dp[j].insert(jump);
                    }
                }
            }
        }

        return !dp[n - 1].empty();
    }
};
