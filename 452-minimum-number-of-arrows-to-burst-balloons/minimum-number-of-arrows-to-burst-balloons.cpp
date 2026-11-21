class Solution {
public:
     static bool comp(vector<int>&val1,vector<int>&val2){
        return val1[1]<val2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int count=1;
        int lastEnd=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>lastEnd){
                count++;
                lastEnd=points[i][1];
            }
        }
        return count;
    }
};