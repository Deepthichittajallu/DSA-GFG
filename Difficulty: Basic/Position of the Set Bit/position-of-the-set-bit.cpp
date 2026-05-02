class Solution {
  public:
    int findPosition(int n) {
        // code here
        if((n&n-1)== 0)
        {
            
            return (log(n)/log(2))+1;
        }
        return -1;
    }
};