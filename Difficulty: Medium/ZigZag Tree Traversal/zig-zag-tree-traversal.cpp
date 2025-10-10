/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<vector<int>>res;
        // int lvl = 0;
        if(root == nullptr)
        {
            return {};
        }
        queue<Node* > q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int>lvl;
            for(int i=0;i<n;i++)
            {
                Node* node = q.front();
                q.pop();
                lvl.push_back(node->data);
            if(node->left != nullptr)
            {
                q.push(node->left);
            }
            if(node->right != nullptr)
            {
                q.push(node->right);
            }
            }
            res.push_back(lvl);
        }
        vector<int>v;
        for(int i=0;i<res.size();i++)
        {
            if(i%2 == 1)
            {
                reverse(res[i].begin(),res[i].end());
            }
            for(int j=0;j<res[i].size();j++)
            {
                v.push_back(res[i][j]);
            }
            // cout<<endl;
        }
        return v;
    }
};