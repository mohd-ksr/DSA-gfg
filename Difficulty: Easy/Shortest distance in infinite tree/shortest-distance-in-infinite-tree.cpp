
class Solution {
  public:
    int distance(int x, int y) {
        // code here
        int count = 0;
        while(x!=y){
            if(x>y)x>>=1;
            else y>>=1;
            count++;
        }
        return count;
    }
};