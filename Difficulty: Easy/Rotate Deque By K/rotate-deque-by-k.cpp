class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type == 1)
        {
            int i=0;
            while(i<k)
            {
                int a = dq.back();
                dq.pop_back();
                dq.push_front(a);
                i++;
            }
        }
        else if(type == 2)
        {
            int i=0;
            while(i<k)
            {
                int a = dq.front();
                dq.pop_front();
                dq.push_back(a);
                i++;
            }
        }
    }
};