class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int sign = 1, res = 0, idx = 0;

    // Ignore leading whitespaces
    while (idx < s.size() && s[idx] == ' ') {
        idx++;
    }

    // Store the sign of number
    if (idx < s.size() && s[idx] == '-' || s[idx] == '+') {
      	if(s[idx++] == '-')
          sign = -1;
    }

    // Construct the number digit by digit
    while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
        
        // handling overflow/underflow test case
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] - '0' > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
      
        // Append current digit to the result
        res = 10 * res + (s[idx++] - '0');
    }
    return res * sign;
    }
};
