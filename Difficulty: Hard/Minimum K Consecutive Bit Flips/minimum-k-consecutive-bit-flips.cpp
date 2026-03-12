class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
         int n = arr.size(); 
    int res = 0, flag = 0;
    vector<int> flipped(n + 1, 0); 

    for (int i = 0; i < n; i++) {
        flag = (flag ^ flipped[i]);
        if(flag == 1)
            arr[i] ^= 1;
            if(arr[i] == 0) {
                if(i + k > n) 
                return -1;
            
            res += 1;
            flag ^= 1;
            flipped[i + k] = 1;
        }
    }

    return res; 
    }
};