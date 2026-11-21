class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //if(intervals.size()==0) return [];
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto &it:intervals){
            if(ans.empty()|| it[0]>ans.back()[1]){
                ans.push_back(it);
            }
            else ans.back()[1]=max(ans.back()[1],it[1]);
        }
        return ans;
    }

};