class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int maxi = *max_element(arr.begin(),arr.end());
        vector<bool>v(maxi+1,0);
        for(int i=0;i<arr.size();i++)
        {
            v[arr[i]] = true;
        }
        for(int i=1;i<=maxi;i++)
        {
            if(v[i] == false) continue;
            for(int j=1;j<=maxi;j++)
            {
                if(v[j] == false) continue;
                int c = sqrt(i*i + j*j);
                if((c*c) != (i*i + j*j) || c > maxi) continue;
                else if(v[c] == true) return true;
            }
        }
        return false;
    }
};