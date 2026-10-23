class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()<=2) return true;
        sort(arr.begin(),arr.end());
        int diff=arr[1]-arr[0];
        bool ans=false;
        for(int i=1;i<arr.size()-1;i++){
            if(diff==(arr[i+1]-arr[i])){
                ans=true;
            }
            else{
                ans=false;
                break;
            }

        }
        return (ans==true)? true:false;
    }
};