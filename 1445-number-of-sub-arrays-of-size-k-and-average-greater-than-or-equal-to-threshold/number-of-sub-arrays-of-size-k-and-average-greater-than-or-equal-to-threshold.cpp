class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0,r=k,n=arr.size();
        int result_value=0;
        int sum=0;
        float avg=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        avg=(double)sum/k;//as sum and k are integers but avg could be float/double
        if(avg>=threshold){
            result_value+=1;
        }
        while(r<n){
            sum-=arr[l];
            sum+=arr[r];
            l++;
            r++;
            avg=(double)sum/k;
            if(avg>=threshold){
                result_value+=1;
            }
        }
        return result_value;
    }
};