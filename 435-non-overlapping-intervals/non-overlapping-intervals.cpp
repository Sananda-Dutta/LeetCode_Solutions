class Solution {
public:
    static bool comp(vector<int>&val1,vector<int>& val2){
        return val1[1]<val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int count=1;
        int lastEndTime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastEndTime){
                count++;
                lastEndTime=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};