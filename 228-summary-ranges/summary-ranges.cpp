class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() < 1) return {};
        if(nums.size() == 1)return {to_string(nums[0])};
        vector<string> ans;
        int a = nums[0];
        int b = nums[0];
        for(int i = 0; i < nums.size();)
        {
            if(i+1 < nums.size() && nums[i+1] == b+1)
            {
                b = nums[i+1];
                i++;
            }
            else
            {
                string s = to_string(a);
                s += "->";
                s += to_string(b);
                if(a != b)
                    ans.push_back(s);
                else
                    ans.push_back(to_string(a));

                if(i+1 < nums.size())
                {
                    a = nums[i+1];
                    b = nums[i+1];
                }
                i++;
            }
        }

        return ans;
        
    }
};