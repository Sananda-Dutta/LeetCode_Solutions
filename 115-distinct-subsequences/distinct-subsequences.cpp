/*
class Solution {
public:
    void subsequence(string &s,int i, string& curr,unordered_map<string,int>&mp){
        if(i==(int)s.size()){
            mp[curr]++;
            return ;
        }
        curr.push_back(s[i]);
        subsequence(s,i+1,curr,mp);
        curr.pop_back();
        subsequence(s,i+1,curr,mp);
    }
    int numDistinct(string s, string t) {
        unordered_map<string,int>mp;
        string curr="";
        subsequence(s,0,curr,mp);
        return(mp[t]);

    }
};
*/

//the previous app only passes 42/62 test cases
class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = m; j >= 1; j--) {

                if (s[i] == t[j - 1]) {

                    dp[j] = min(2147483647LL,
                                dp[j] + dp[j - 1]);
                }
            }
        }

        return (int)dp[m];
    }
};