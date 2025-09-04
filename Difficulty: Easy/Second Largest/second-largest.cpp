class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = -1, secondLargest = -1;
        for(auto &n:arr){
            if(n>largest){
                secondLargest = largest;
                largest = n;
            }
            if(n<largest && n>secondLargest){
                secondLargest = n;
            }
        }
        return secondLargest;
    }
};