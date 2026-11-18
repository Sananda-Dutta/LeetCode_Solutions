class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        for(int j=nums1.size()-1;j>=0;j--){
            if(i!=n && nums1[j]==0){
                nums1[j]=nums2[i];
                i++;
            }
        }
        sort(nums1.begin(),nums1.end());
    }
};