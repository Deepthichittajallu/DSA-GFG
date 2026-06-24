class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int  l = 0;
        int r = height.size() - 1;
        int area = 0;
        while(l<=r)
        {
            area = max(area,min(height[l],height[r]) * (r-l-1));
            // cout<<area<<endl;
           if(height[l] < height[r]) l++;
           else r--;
        }
        return area;
    }
};