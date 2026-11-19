class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int ans=0;
        for(int i=0;i<t.size()-1;i++){
            if(t[i+1]>(d+t[i])){
                ans+=d;
            }
            else{
                ans+=(t[i+1]-t[i]);
            }
        }
        ans+=d;
        return ans;
    }
};