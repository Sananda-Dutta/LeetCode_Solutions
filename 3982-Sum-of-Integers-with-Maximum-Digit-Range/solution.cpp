
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<pair<int, int>> v;
        int max_freq = 0;
        
        for (int num : nums) {
            int copy = num;
            int mini = 9, maxi = 0;
            
            while (copy > 0) {
                int digit = copy % 10;
                mini = min(mini, digit);
                maxi = max(maxi, digit);
                copy /= 10;
            }
            
            int range = maxi - mini;
            v.push_back({num, range});
            max_freq = max(max_freq, range);
        }
        
        int sum = 0;
        for (auto &x : v) {
            if (x.second == max_freq) {
                sum += x.first;
            }
        }
        
        return sum;
    }
};
