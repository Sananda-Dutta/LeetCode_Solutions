class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int>set;
        for(int ele : nums){
            set.insert(ele);
        }
        int count =0;
        for(int ele : set){
            if(set.count(ele+diff) && set.count(ele+2*diff)){
                count++;
            }
        }
        return count;
    }
};