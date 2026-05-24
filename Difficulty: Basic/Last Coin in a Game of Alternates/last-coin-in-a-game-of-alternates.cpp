class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int i = 0;
        int n = arr.size();
        int j = n-1;
        while(i<j)
        {
            if(arr[i] > arr[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return arr[i];
    }
};