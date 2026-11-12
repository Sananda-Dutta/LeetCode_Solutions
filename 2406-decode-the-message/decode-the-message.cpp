class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        string copy="";
        for(int i=0;i<key.size();i++){
            if(key[i]==' ') continue;
            else copy+=key[i];
        }
        int j=0;
        for(int i=0;i<copy.size();i++){
            if(mp.find(copy[i])==mp.end()){
                mp[copy[i]]=char(97+j);
                j++;
            }
            
        }
        string ans="";
        for(int i=0;i<message.size();i++){
            if(message[i]==' ') ans+=' ';
            else ans+=(mp[message[i]]);
        }
        return ans;
    }
};