class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        /*
        if(trust.size()==0) return 1;
        if(n==1) return 1;
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++){
            mp.try_emplace(trust[i][0],trust[i][1]);
        }

        int leader=trust[0][1];
        for(int i=0;i<trust.size();i++){
            if(mp.find(trust[i][0])!=mp.end()){
                if(mp[trust[i][0]]!=leader){
                    return -1;
                }
            }
        }
        return (leader>0)? leader:-1;
        */
        if(n == 1) return 1;

        unordered_map<int,int> mp;

        for(int i = 0; i < trust.size(); i++) {

            mp[trust[i][0]]--;
            mp[trust[i][1]]++;
        }

        for(int i = 1; i <= n; i++) {

            if(mp[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
};