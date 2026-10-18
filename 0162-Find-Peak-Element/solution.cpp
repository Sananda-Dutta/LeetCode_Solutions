class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi=INT_MIN;
        int max_idx=0;
        //if(nums.size()<=1) return nums[]
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                max_idx=i;
            }
        }
        return max_idx;
    }
};