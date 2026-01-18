class Solution {
private:
    void calculate(int n, string temp, vector<string>&ans){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        calculate(n-1, temp+"0", ans);
        calculate(n-1, temp+"1", ans);
    }
public:
    vector<string> binstr(int n) {
        vector<string>ans;
        calculate(n,"",ans);
        return ans;
    }
};



// // User function Template for C++

// class Solution {
//   private:
//     void generate(int n,string current,vector<string>&ans,char prev){
//         if(n==0){
//             ans.push_back(current);
//             return;
//         }
//         generate(n-1,current+"0",ans,'0');
        
//         generate(n-1,current+"1",ans,'1'); 
        
//     }
//   public:
//     vector<string> binstr(int num) {
//         // Write your code
//         vector<string>ans;
//         generate(num,"",ans,'0');
//         return ans;
//     }
// };


