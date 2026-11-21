class Solution {
public:
    static bool comp(vector<int>& p1,vector<int>&p2){
        return p1[1]<p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int count=1;
        sort(pairs.begin(),pairs.end(),comp);
        int lastEnd=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(lastEnd<pairs[i][0]){
                count++;
                lastEnd=pairs[i][1];
            }
        }
        return count;
    }
};