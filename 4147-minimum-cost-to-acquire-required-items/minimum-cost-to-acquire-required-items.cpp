class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long ans1=0,ans2=0,ans3=0;
        if(need1==0 &&need2==0) return 0;

        ans1=max(need1,need2)*costBoth;
        ans2=need1*cost1+need2*cost2;

        if(need1>need2) ans3=need2*costBoth+(need1-need2)*cost1;
        else ans3=need1*costBoth+(need2-need1)*cost2;
       
        return min(ans1,min(ans2,ans3));
    }
};