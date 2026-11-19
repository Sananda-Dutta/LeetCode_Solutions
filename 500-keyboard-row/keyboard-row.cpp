class Solution {
public:
    bool first_row(char d){
        char c=tolower(d);
        return (c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y'||c=='u'
        ||c=='i'||c=='o'||c=='p');
    }

    bool sec_row(char d){
        char c=tolower(d);
        return (c=='a'||c=='s'||c=='d'||c=='f'||c=='g'||c=='h'||c=='j'
        ||c=='k'||c=='l');
    }

    bool third_row(char d){
        char c=tolower(d);
        return (c=='z'||c=='x'||c=='c'||c=='v'||c=='b'||c=='n'||c=='m');
    }

    vector<string> findWords(vector<string>& words) {
        vector<string>vec;
        for(int i=0;i<words.size();i++){
            bool found=true;
            int row=0;
            if(first_row(words[i][0])) row=1;
            else if(sec_row(words[i][0])) row=2;
            else row=3;
            for(int j=1;j<words[i].size();j++){
                if(row==1 && first_row(words[i][j])){
                    found=true;
                }
                
                else if(row==2 && sec_row(words[i][j])){
                    found=true;
                } 
                else if(row==3 && third_row(words[i][j])){
                    found=true;
                } 
                else {
                    found=false;
                    break;
                }
            }
            if(found) vec.push_back(words[i]);
        }
        return vec;
    }
};