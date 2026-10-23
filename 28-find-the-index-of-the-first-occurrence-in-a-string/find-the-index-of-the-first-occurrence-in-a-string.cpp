class Solution {
public:
    int strStr(string haystack, string needle) {
        unordered_map<string,int>mp;
        for(int i=0;i<=(int)haystack.size()-(int)needle.size();i++){
            string ans="";
            for(int j=i;j<needle.size()+i;j++){
                ans+=haystack[j];
            }
            mp.try_emplace(ans,i);
        }
        if(mp.find(needle)!=mp.end()) return mp[needle];
        return -1;
    }
};