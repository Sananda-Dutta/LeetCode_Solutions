class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
        sort(nums.begin(),nums.end(),[](int a,int b){
            if(a>0 && b>0 && (a)>b) return a>b;//if both +ve
            else if(a>0 && b<0){//if a+ve but b -ve
                if(a>abs(b)) return a>b;
            }
            else if(a<0 && b<0){
                if(abs(a)>abs(b)) return a>b;
            }
            return b>a;
        });

        return (nums[0]*nums[1]*nums[2]);
        */
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[n-1] * nums[n-2] * nums[n-3];
        int b = nums[0] * nums[1] * nums[n-1];
        return max(a, b);
    }
};