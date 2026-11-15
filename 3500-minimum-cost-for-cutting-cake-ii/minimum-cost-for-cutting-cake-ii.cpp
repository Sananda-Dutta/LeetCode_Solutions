class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        long long ans=0;
        sort(hc.begin(),hc.end(),greater<int>());
        sort(vc.begin(),vc.end(),greater<int>());

        int hz_cut=1,vr_cut=1;

        int l1=0;
        int l2=0;
        while(l1<hc.size() && l2<vc.size()){
            if(hc[l1]>vc[l2]){
                ans+=1LL*hc[l1]*vr_cut;
                hz_cut++;
                l1++;
            }
            else{
                ans+=1LL*vc[l2]*hz_cut;
                vr_cut++;
                l2++;
            }
        }
        while(l1<hc.size()){
            ans+=1LL*hc[l1]*vr_cut;
            l1++;
        }
        while(l2<vc.size()){
            ans+=1LL*vc[l2]*hz_cut;
            l2++;
        }
        return ans;
    }
};