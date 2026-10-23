class Solution {
public:
    void generate(vector<string>& arr, int index,
                string current, vector<string>& ans) {

        // Base case: one character chosen from every string
        if (index == arr.size()) {
            ans.push_back(current);
            return;
        }

        // Pick each character from the current string
        for (int i = 0; i < arr[index].size(); i++) {
            generate(arr, index + 1, current + arr[index][i], ans);
        }
    }


    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mp;
        vector<string>vec;
        int n=97;
        for(int i=2;i<=6;i++){
            string s;
            s+=(char)n;
            s+=(char)n+1;
            s+=(char)n+2;
            mp[i]=s;
            n=n+3;
        }
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        for(int i=0;i<digits.size();i++){
            vec.push_back(mp[digits[i]-'0']);
        }
        
        vector<string>ans;
        generate(vec, 0, "", ans);

        return ans;
    }
};