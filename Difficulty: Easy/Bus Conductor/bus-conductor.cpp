class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        int cnt = 0;
        for(int i=0;i<chairs.size();i++)
        {
            cnt += abs(chairs[i] - passengers[i]);
        }
        return cnt;
    }
};