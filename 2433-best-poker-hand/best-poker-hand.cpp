class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char>set;
        for(int i=0;i<suits.size();i++){
            set.insert(suits[i]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<ranks.size();i++){
            mp[ranks[i]]++;
        }
        if(ranks.size()-set.size()>=4) return "Flush";
        else{
            int max_freq=0;
            for(int i=0;i<ranks.size();i++){
                if(mp[ranks[i]]>max_freq){
                    max_freq=mp[ranks[i]];
                }
            }
            if(max_freq>=3) return "Three of a Kind";
            else if(max_freq==2) return "Pair";
            else return "High Card";
        }
        return "";
    }
};