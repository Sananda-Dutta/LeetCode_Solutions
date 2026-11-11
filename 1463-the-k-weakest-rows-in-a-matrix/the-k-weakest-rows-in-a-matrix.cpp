class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>vec;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) count++;
            }
            vec.push_back({i,count});
        }
        sort(vec.begin(),vec.end(),[](const pair<int,int>&a, const pair<int,int>&b) {if(a.second == b.second)
                    return a.first < b.first;

                return a.second < b.second;});

        vector<int>ans;
        int i=0;
        while(k--){
            ans.push_back(vec[i].first);
            i++;
        }
        return ans;
    }
};