/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findMedian(Node* root) {
        // Code here
        queue<Node*>q;
        vector<int>res;
        if(root == nullptr) return 0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* node = q.front();
                res.push_back(node->data);
                q.pop();
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        sort(res.begin(),res.end());
        // for(auto it:res)
        // {
        //     cout<<it<<" ";
        // }
        sort(res.begin(),res.end());
        int n = res.size();
        // if (n % 2 == 0) {
        //     return res[n/2];
        // }
        //     return res[n/2 - 1];
        return res[(n % 2 == 0) ? (n / 2 - 1) : (n / 2)];
    }
};