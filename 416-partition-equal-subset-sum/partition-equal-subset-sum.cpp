class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        vector<bool>prev(target+1,0),curr(target+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=target)prev[nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int t=1;t<=target;t++){
                bool nottake=prev[t];
                bool take=false;
                if(nums[i]<=t) take=prev[t-nums[i]];
                curr[t]=take | nottake;
            }
            prev=curr;
        }
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        if(total_sum%2!=0) return false;
        int target=total_sum/2;
        return isSubsetSum(nums,target);
        /*
        if(nums.size()%2!=0) return false;
        sort(nums.begin(),nums.end());
        int first_half=0;
        int sec_half=0;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            first_half+=nums[i];
            sec_half+=nums[n-i];
            if(first_half==sec_half) return true;
            else if(first_half>sec_half){
                return false;
                break;
            }
        }
        return true;
        */


    }
};