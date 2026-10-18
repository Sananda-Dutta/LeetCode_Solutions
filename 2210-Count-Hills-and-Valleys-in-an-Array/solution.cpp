class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hill=0;
        int valley=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]) hill++;
            else if(nums[i-1]!=nums[i] &&nums[i-1]>nums[i] && nums[i+2]>nums[i]) valley++;
        }
        return hill+valley;
    }
};