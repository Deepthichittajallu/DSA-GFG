/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        // code here
        if(root == nullptr) return 0;
        queue<Node*>q;
        map<Node*,Node*>mp;
        mp[root] = nullptr;
        q.push(root);
        Node* tar = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto node = q.front();
                q.pop();
                if(target == node->data)
                {
                    tar = node;
                }
                if(node->left)
                {
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        int ans = -1;
        map<Node*,bool>vis;
        queue<Node*>q1;
        q1.push(tar);
        while(!q1.empty())
        {
            int n = q1.size();
            for(int i=0;i<n;i++)
            {
                auto node = q1.front();
                vis[node] = true;
                q1.pop();
                if(node->left !=nullptr && vis[node->left] != true)
                {
                    q1.push(node->left);
                }
                if(node->right != nullptr && vis[node->right] != true)
                {
                    q1.push(node->right);
                }
                if(mp[node] != nullptr && vis[mp[node]] != true)
                {
                    q1.push(mp[node]);
                }
            }
            ans++;
        }
        return ans;
        
    }
};