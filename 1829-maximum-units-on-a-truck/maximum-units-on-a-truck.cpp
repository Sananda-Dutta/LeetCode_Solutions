class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int sum=0;
        int ans=0;

        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a, vector<int>&b){
            if(a[1]==b[1]) return a[0]>b[0];
            else return a[1]>b[1];
        });

        int i=0;
        while(truckSize>0 && i<boxTypes.size()){
            if(boxTypes[i][0]<=truckSize){
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            else{
                ans+=(truckSize*boxTypes[i][1]);
                break;
            }
            i++;
        }
        return ans;
    }
};