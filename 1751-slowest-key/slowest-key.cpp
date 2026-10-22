class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans=keysPressed[0];
        int max_time=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
            int time=releaseTimes[i]-releaseTimes[i-1];
            if(max_time<time|| max_time==time && (int)(keysPressed[i]-'a')>(int)ans-'a'){
                max_time=time;
                ans=keysPressed[i];
            }
        }
        return ans;
    }
};