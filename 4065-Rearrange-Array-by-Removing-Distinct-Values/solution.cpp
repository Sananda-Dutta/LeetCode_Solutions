class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(int x:nums){
            mp[x]++;
        }

        while(ans.size()!=nums.size()){
            for(auto it = mp.begin(); it != mp.end(); ) {

                ans.push_back(it->first);
                it->second--;

                if(it->second == 0) {
                    it = mp.erase(it); //using iterator bez here if wanna 
                    //erase in the mp 
                }
                else {
                    ++it;
                }
            }
        }
        return ans;
    }
};