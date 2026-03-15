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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        if(root == nullptr) return {{}};
        vector<vector<int>>res;
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        int dis = 0;
        q.push({root,0});
        int d = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto node = q.front();
                auto val = node.first;
                int dist = node.second;
                q.pop();
                mp[dist].push_back(val->data);
                if(val -> left) q.push({val->left,dist-1});
                if(val -> right) q.push({val->right,dist+1});
            }
        }
        for(auto it:mp)
        {
            // cout<<it.first<<"-->"<<" ";
            // auto v = it.second;
            // for(int i=0;i<v.size();i++)
            // {
            //     cout<<v[i]<<" ";
            // }
            // cout<<endl;
            res.push_back(it.second);
        }
        return res;
    }
};