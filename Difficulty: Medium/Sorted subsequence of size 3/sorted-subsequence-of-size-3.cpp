class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<int>v1(n,-1);
        vector<int>v2(n,-1);
        int mini = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] <= arr[mini])
            {
                mini = i;
            }
            else v1[i] = mini;
        }
        int maxi = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] >= arr[maxi])
            {
                maxi = i;
            }
            else v2[i] = maxi;
        }
        for(int i=0;i<n;i++)
        {
            if(v1[i] != -1 && v2[i] != -1 )
            {
                return {arr[v1[i]],arr[i],arr[v2[i]]};
            }
        }
        return {};
    }
};