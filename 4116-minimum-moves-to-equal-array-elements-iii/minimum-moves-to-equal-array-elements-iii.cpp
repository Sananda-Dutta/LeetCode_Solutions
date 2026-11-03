class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) maxi=nums[i];
        }
        int steps=0;
        for(int i=0;i<nums.size();i++){
            int diff=maxi-nums[i];
            steps+=diff;
        }
        return steps;
    }
};