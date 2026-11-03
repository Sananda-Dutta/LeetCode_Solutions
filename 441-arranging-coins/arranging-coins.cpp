class Solution {
public:
    int arrangeCoins(int n) {
        int count=0;
        int i=1;
        while(n>=i){
            int sum=0;
            sum+=i;
            i++;
            count++;
            n-=sum;
        }
        return count;
    }
};