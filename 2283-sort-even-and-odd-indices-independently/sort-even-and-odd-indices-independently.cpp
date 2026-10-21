
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> odd, even;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());

        int e = 0, o = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                ans[i] = even[e++];
            else
                ans[i] = odd[o++];
        }

        return ans;
    }
};
