class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0,b=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R'){
                a++;
            }
            else if(moves[i]=='L'){
                a--;
            }
            else if(moves[i]=='U'){
                b++;
            }
            else if(moves[i]=='D'){
                b--;
            }
        }
        return (a==0 && b==0)? true:false;
    }
};