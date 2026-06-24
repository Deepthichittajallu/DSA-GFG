class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int ans = 0;
        for(int i=0;i<=sqrt(p);i++)
        {
            int temp = (i * (i + 1) * (2*i + 1))/6;
            if(temp <= p)
            {
                ans = i;
            }
            else break;
        }
        return ans;
    }
};
