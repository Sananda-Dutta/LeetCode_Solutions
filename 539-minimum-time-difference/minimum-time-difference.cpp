class Solution {
public:
    int get_min(string t){
        int hours = (t[0] - '0') * 10 + (t[1] - '0');
        int mins = (t[3] - '0') * 10 + (t[4] - '0');
        return hours * 60 + mins;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(auto m:timePoints){
            minutes.push_back(get_min(m));
        }

        sort(minutes.begin(),minutes.end());
        int min_diff=INT_MAX;
        for(int i=1;i<minutes.size();i++){
            min_diff=min(min_diff,minutes[i]-minutes[i-1]);
        }
        return min(min_diff,abs(minutes[0]+1440-minutes[minutes.size()-1]));
    }
};