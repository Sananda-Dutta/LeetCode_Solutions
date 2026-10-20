class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans=words;
        for(int i=words.size()-1;i>=1;i--){
            unordered_map<char,int>mp;
            for(char c:words[i]){
                mp[c]++;
            }
            for(char c:words[i-1]){
                mp[c]--;
                if(mp[c]==0)  mp.erase(c);
            }

            if(mp.size()==0){
                ans.erase(ans.begin()+i);
            }
        }
        //reverse(ans.begin(),ans.end());
        return ans; 
    }
};