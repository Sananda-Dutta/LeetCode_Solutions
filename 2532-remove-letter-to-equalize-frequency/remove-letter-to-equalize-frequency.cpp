
class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> mp;
        for(char c : word) {
            mp[c]++;
        }
        for(auto &it : mp) {
            it.second--;
            int freq = 0;
            bool valid = true;
            for(auto p : mp) {
                if(p.second == 0) continue;
                if(freq == 0) {
                    freq = p.second;
                }
                else if(freq != p.second) {
                    valid = false;
                    break;
                }
            }

            if(valid) return true;
            it.second++;
        }

        return false;
    }
};
