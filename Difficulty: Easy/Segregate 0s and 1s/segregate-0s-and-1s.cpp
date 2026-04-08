class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i = 0;
        int j = 0;
        for(i=0;i<arr.size();i++)
        {
            if(arr[i] == 0)
            {
                arr[j++] = 0;
            }
        }
        for(i = j;i<arr.size();i++)
        {
            arr[i] = 1;
        }
        
    }
};