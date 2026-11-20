class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        //vector<int> vec;

        vector<int> ans;
        int i = num.size() - 1;
        int carry = 0;
        while (i >= 0 || k > 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i];
                i--;
            }
            if (k > 0) {
                sum += k % 10;
                k /= 10;
            }
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        /*
        string s=to_string(k);
        int j=s.size()-1;
        for(int i=num.size()-1;i>=0;i--){
            if(j>=0 && (num[i]-'0')+(s[j]-'0')<=9){
                num[i]=(num[i]-'0')+(s[j]-'0');
                j--;
            }

        }

        
        string s="";
        for(int i=0;i<num.size();i++){
            s+=(num[i]+'0');
        }
        long long ans=stol(s)+k;
        while(ans!=0){
            int digit=ans%10;
            vec.push_back(digit);
            ans/=10;
        }
        reverse(vec.begin(),vec.end());
        return vec;
        */



    }
};