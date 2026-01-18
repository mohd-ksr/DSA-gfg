class Solution {
private:
    void cal(vector<int>&nums, int i, int sum, vector<int>&ans){
        if(i==nums.size()){
            ans.push_back(sum);
            return;
        }
        cal(nums, i+1, sum, ans);
        cal(nums, i+1, sum+nums[i], ans);
    }
public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        cal(arr, 0, 0, ans);
        return ans;
    }
};