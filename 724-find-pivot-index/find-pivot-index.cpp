class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int left_sum=0;
        int right_sum=total;
        for(int i=0;i<nums.size();i++){
            if(left_sum==(right_sum-nums[i])){
                return i;
            }
            else{
                left_sum+=nums[i];
                right_sum-=nums[i];
            }
        }
        return -1;
    }
};