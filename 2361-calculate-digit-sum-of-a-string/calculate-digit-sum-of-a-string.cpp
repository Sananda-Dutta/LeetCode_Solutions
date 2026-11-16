
class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;
        while(s.size() > k) {
            vector<string> vec;
            for(int i = 0; i < s.size(); ) {
                vec.push_back(s.substr(i, k));
                i += k;
            }
            s.clear();
            for(int i = 0; i < vec.size(); i++) {
                int sum = 0;
                for(char ch : vec[i]) {
                    sum += ch - '0';
                }
                s += to_string(sum);
            }
        }
        return s;
    }
};
