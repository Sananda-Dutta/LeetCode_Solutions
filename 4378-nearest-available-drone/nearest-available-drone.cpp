class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=-1;
        int min_diff=INT_MAX;
        for(int i=0;i<drones.size();i++){
            int a=abs(drones[i][0]-target[0]);
            int b=abs(drones[i][1]-target[1]);
            int diff=(a+b);

            if(diff<=drones[i][2] && diff<min_diff){
                min_diff=diff;
                ans=i;
            }
        }
        return ans;
    }
};