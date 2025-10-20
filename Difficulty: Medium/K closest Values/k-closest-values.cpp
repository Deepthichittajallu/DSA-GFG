/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        queue<Node*>q;
        vector<pair<int,int>>v;
        if(root == nullptr) return {};
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* node = q.front();
                v.push_back({abs(target-(node->data)),node->data});
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }
        sort(v.begin(),v.end());
        vector<int>res;
        // for(auto it:v)
        // {
        //     cout<<it.first<<" "<<it.second;
        //     cout<<endl;
        // }
        for(int i=0;i<k;i++)
        {
            res.push_back(v[i].second);
        }
        return res;
    }
};