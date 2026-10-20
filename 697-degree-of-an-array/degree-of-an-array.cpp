
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;

        int degree = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (first.find(x) == first.end()) {
                first[x] = i;
            }

            last[x] = i;
            freq[x]++;

            degree = max(degree, freq[x]);
        }

        for (auto& p : freq) {
            int x = p.first;

            if (p.second == degree) {
                int len = last[x] - first[x] + 1;
                ans = min(ans, len);
            }
        }

        return ans;
    }
};
