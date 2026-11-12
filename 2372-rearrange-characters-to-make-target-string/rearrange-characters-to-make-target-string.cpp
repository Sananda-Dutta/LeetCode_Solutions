class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp1, mp2;

        for(char c : s) {
            mp1[c]++;
        }

        for(char c : target) {
            mp2[c]++;
        }

        int ans = INT_MAX;

        for(auto it : mp2) {
            char c = it.first;

            ans = min(ans, mp1[c] / it.second);
        }

        return ans;
    }
};