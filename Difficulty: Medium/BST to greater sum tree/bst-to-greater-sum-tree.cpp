/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

void pre(Node* root,vector<int>&res)
{
    if(root == nullptr) return;
    res.push_back(root->data);
    pre(root->left,res);
    pre(root->right,res);
}
class Solution {
  public:
    void transformTree(Node *root) {
        // code here
        // Node* node = root;
        vector<int>res;
        pre(root,res);
        int n = res.size();
        sort(res.begin(),res.end());
        vector<int>pref(n);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += res[i];
            pref[i] = sum;
        }
        map<int,int>mp;
        for(int i=0;i<res.size();i++)
        {
            mp[res[i]] += pref[i];
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* node = q.front();
                q.pop();
                node -> data = (sum - mp[node->data]);
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
    }
};