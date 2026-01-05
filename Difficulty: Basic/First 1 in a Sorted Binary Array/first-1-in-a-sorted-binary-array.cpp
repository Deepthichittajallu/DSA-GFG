class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        // Your code goes here
        int i =-1;
        int j = arr.size();
        while(j-i > 1)
        {
            int mid = i+(j-i)/2;
            if(arr[mid] < 1) i = mid;
            else j = mid;
        }
        // cout<<i<<" "<<j;
        if(j>=arr.size()) return -1;
        return j;
    }
};