class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(),citations.end(),greater<int>());
        int i=0;
        while(i<citations.size() && citations[i] > i)
        {
            i++;
        }
        return i;
    }
};