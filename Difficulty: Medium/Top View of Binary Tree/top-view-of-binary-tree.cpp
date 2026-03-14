/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if(root == NULL) return {};
        int cnt = 0;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        int mini = INT_MAX;
        while(!q.empty())
        {
           auto node = q.front().first;
           int dis = q.front().second;
           q.pop();
           mini = min(mini,dis);
           if(mp.find(dis) == mp.end())
           {
               mp[dis] = node->data;
           }
           if(node->left) q.push({node->left,dis - 1});
           if(node->right) q.push({node->right,dis+1});
        }
        vector<int>res(mp.size());
       for(auto it:mp)
       {
           res[it.first - mini] = it.second;
       }
        return res;
    }
};