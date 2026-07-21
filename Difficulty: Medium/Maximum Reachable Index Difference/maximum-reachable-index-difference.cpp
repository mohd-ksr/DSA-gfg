class Solution {
public:
    int maxIndexDifference(string &s) {
        
        char prev = 'a' - 1;
        int st = -1;
        int e = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i]==(prev+1)){
                if(st==-1)st=i;
                prev = s[i];
                e=i;
            }
            if(s[i]>'a' && s[i]<=prev){
                e=i;
            }
        }
        if(prev=='a'-1)return -1;
        return e-st;
    }
};
