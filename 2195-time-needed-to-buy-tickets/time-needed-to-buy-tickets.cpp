class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        long long ans=0;
        int target=tickets[k];
        int i=0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                ans+=min(tickets[i],target);
            }
            else{
                ans+=min(target-1,tickets[i]);
            }
        }
        return (int)ans;
    }
};