class Solution {
  public:
  int merge(vector<int>&arr,int l,int m,int r)
  {
      int n1 = m-l+1;
      int n2 = r-m;
      vector<int>r1(n1),r2(n2);
      for(int i=0;i<n1;i++)
      {
          r1[i] = arr[i+l];
      }
      for(int j=0;j<n2;j++)
      {
          r2[j] = arr[m+1+j];
      }
      int i=0,j=0,res =0,k=l;
      while(i<n1 && j < n2)
      {
          if(r1[i] <= r2[j])
          {
              arr[k++] = r1[i++];
          }
          else
          {
              arr[k++] = r2[j++];
              res += (n1-i);
          }
        }
        while(i<n1)
        {
            arr[k++] = r1[i++];
        }
        while(j<n2)
        {
            arr[k++] = r2[j++];
        }
        return res;
  }
  int divide(vector<int>&arr,int l, int r)
  {
       int res = 0;
      if(l<r)
      {
          int m = (r+l)/2;
          res += divide(arr,l,m);
          res += divide(arr,m+1,r);
          res += merge(arr,l,m,r);
      }
      return res;
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        divide(arr,0,n-1);
    }
};