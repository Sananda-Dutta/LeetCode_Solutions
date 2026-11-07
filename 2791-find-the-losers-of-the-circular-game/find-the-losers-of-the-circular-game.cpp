class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool>arr(n,false);
        int count=1;
        int i=0;
        while(arr[i]==false){
            arr[i]=true;
            i=(i+(k*count))%n;
            count++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]==false) ans.push_back(i+1);
        }
        return ans;
    }
};