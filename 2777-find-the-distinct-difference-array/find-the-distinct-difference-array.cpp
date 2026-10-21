class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>vec;
        int i=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>left,right;
            for(int j=0;j<=i;j++){
                left[nums[j]]++;
            }
            for(int j=i+1;j<nums.size();j++){
                right[nums[j]]++;
            }
            int diff=left.size()-right.size();
            vec.push_back(diff);
        }
        return vec;

    }
};