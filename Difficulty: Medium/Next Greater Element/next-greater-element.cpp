class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            if(st.empty())st.push(arr[i]);
            else{
                while(!st.empty() && arr[i]>=st.top())st.pop();
                
                if(!st.empty())ans[i]=st.top();
                st.push(arr[i]);
            }
        }
        return ans;
        
    }
};