class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> bitCount(32, 0);

        int left = 0;
        int currOR = 0;
        for (int right = 0; right < n; right++) {
            for (int b = 0; b < 32; b++) {
                if (nums[right] & (1 << b)) {
                    bitCount[b]++;
                    currOR |= (1 << b);
                }
            }
            while (left <= right && currOR >= k) {
                ans = min(ans, right - left + 1);
                for (int b = 0; b < 32; b++) {
                    if (nums[left] & (1 << b)) {
                        bitCount[b]--;

                        if (bitCount[b] == 0) {
                            currOR &= ~(1 << b);
                        }
                    }
                }

                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};