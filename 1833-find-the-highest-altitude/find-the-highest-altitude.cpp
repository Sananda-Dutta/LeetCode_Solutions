class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=gain[0];
        vector<int>vec;
        vec.push_back(0);
        vec.push_back(gain[0]);
        for(int i=1;i<gain.size();i++){
            vec.push_back(vec[i]+gain[i]);
        }
        for(int i=0;i<vec.size();i++){
            ans=max(vec[i],ans);
        }
        return ans;
    }
};