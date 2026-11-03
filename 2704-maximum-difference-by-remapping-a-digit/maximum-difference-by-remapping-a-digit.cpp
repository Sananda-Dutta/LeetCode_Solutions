class Solution {
public:
    int minMaxDifference(int num) {

        string s = to_string(num);
        string maxi = s;

        char digit = ' ';

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                digit = s[i];
                break;
            }
        }

        if (digit != ' ') {
            for (int i = 0; i < maxi.size(); i++) {
                if (maxi[i] == digit) {
                    maxi[i] = '9';
                }
            }
        }
        string mini = s;
        digit = s[0];
        for (int i = 0; i < mini.size(); i++) {
            if (mini[i] == digit) {
                mini[i] = '0';
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
