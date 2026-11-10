class Solution {
public:
    bool isvowel(char c){
        return (c=='a'||c=='i'||c=='o'||c=='u'||c=='e'||c=='A'||c=='I'||c=='O'||c=='U'||c=='E');
    }
    string toGoatLatin(string sentence) {
        string ans="";
        stringstream ss(sentence);
        string word;
        int a=1;
        while(ss>>word){
            if(isvowel(word[0])){
                ans+=word;
                ans+="ma";
            }
            else{
                char c=word[0];
                word.erase(word.begin()+0);
                ans+=word;
                ans+=c;
                ans+="ma";
            }
            int copy=a;
            while(a--){
                ans+='a';
            }
            ans+=" ";
            a=copy;
            a++;
        }
        ans.pop_back();
        return ans;
    }
};