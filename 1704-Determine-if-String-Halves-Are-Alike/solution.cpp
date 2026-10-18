class Solution {
public:
    bool isvowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
    bool halvesAreAlike(string s) {
        int count1=0;
        int count2=0;
        for(int i=0;i<s.size()/2;i++){
            if(isvowel(s[i])){
                count1++;
            }
        }
        for(int i=s.size()/2;i<s.size();i++){
            if(isvowel(s[i])){
                count2++;
            }
        }
        return(count1==count2);
    }
};