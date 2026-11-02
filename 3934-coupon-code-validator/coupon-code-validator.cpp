/*
class Solution {
public:
    bool valid_business(string s){
        return (s=="electronics"||s=="grocery"||s=="pharmacy"||s=="restaurant");
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>ans;
        for(int i=0;i<code.size();i++){
            if(valid_business(businessLine[i]) && isActive[i]==true && !code[i].empty()){
                bool valid=true;
                for(int j=0;j<code[i].size();j++){
                    if(!isalnum(code[i][j])&& code[i][j] != '_'){
                        valid=false;
                        break;
                    }
                }
                if(valid) ans.push_back(code[i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
*/

class Solution {
public:

    bool valid_business(string s) {
        return (s == "electronics" ||
                s == "grocery" ||
                s == "pharmacy" ||
                s == "restaurant");
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<int, string>> temp;

        for (int i = 0; i < code.size(); i++) {

            if (valid_business(businessLine[i]) &&
                isActive[i] == true &&
                !code[i].empty()) {

                bool valid = true;

                for (int j = 0; j < code[i].size(); j++) {

                    if (!isalnum((unsigned char)code[i][j]) &&
                        code[i][j] != '_') {

                        valid = false;
                        break;
                    }
                }
                if (valid) {

                    int category;

                    if (businessLine[i] == "electronics")
                        category = 0;
                    else if (businessLine[i] == "grocery")
                        category = 1;
                    else if (businessLine[i] == "pharmacy")
                        category = 2;
                    else
                        category = 3;

                    temp.push_back({category, code[i]});
                }
            }
        }

        sort(temp.begin(), temp.end());

        vector<string> ans;

        for (auto &p : temp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
