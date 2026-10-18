class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hill=0;
        int valley=0;
        unordered_set<int>set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        for(int i=1;i<set.size()-1;i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]) hill++;
            else if(nums[i-1]>nums[i] && nums[i+1]>nums[i]) valley++;
        }
        return hill+valley;
    }
};