class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
        vector<int> ans;
        int n=0;
        for(int i=0;i<digits.size();i++){
            n=(n*10)+digits[i];
        }

        int next_number=n+1;
        int count=0;
        while(next_number>0){
            int digit=next_number%10;
            count++;
            n=n/10;
        }
        for(int i=0;i<count;i++){

        }
        */
        /*
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]+=1;
            }
            else if(digits[i]==9){
                while(digits[i]!=9){
                    digits[i-1]=1;
                }
            }
        }
        
        string s;
        for(int i=0;i<digits.size();i++){
            s+=(digits[i]+'0');
        }
        long long n=stol(s)+1;
        string ans=to_string(n);
        vector<int>vec;
        for(int i=0;i<ans.size();i++){
            vec.push_back(ans[i]-'0');
        }
        return vec;
        */
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};