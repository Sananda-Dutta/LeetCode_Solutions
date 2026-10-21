class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min_dist=nums[0];
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<abs(min_dist)|| abs(nums[i])==abs(min_dist) && nums[i]>min_dist) min_dist=nums[i];
        }
        return min_dist;
    }
};