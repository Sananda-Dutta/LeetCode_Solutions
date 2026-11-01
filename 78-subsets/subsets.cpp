class Solution {
public:
    void subsequence(const vector<int>& nums,int i,vector<int>&curr,vector<vector<int>>&ans){
        if(i==(int)nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subsequence(nums,i+1,curr,ans);
        curr.pop_back();
        subsequence(nums,i+1,curr,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> curr;
        subsequence(nums,0,curr,ans);
        return ans;
    }
};