class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int max_idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                max_idx=i;
            }
        }
        return max_idx;
    }
};