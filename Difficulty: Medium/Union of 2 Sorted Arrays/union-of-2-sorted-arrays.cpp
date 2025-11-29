class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<n && j<m){
            while(i+1<n && a[i]==a[i+1]){
                i++;
            }
            while(j+1<m && b[j]==b[j+1]){
                j++;
            }
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j])ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i<n){
            while(i+1<n && a[i]==a[i+1]){
                i++;
            }
            ans.push_back(a[i++]);
        }
        while(j<m){
             while(j+1<m && b[j]==b[j+1]){
                j++;
            }
            ans.push_back(b[j++]);
        }
        return ans;
    }
};