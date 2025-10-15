/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        if(root == nullptr) return -1;
        queue<Node*>q;
        q.push(root);
        vector<int>v;
        set<int>st;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* node = q.front();
                q.pop();
                v.push_back(node->data);
                st.insert(node->data);
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!= nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        int ans = 0;
        sort(v.begin(),v.end());
        // for(auto it:v)
        // {
        //     cout<<it<<" ";
        // }
        if(v.size() < k) return -1;
        int cnt = 1;
        for(auto it:v)
        {
            if(cnt == k)
            {
                ans = it;
                break;
            }
            else
            {
                cnt++;
            }
        }
        return ans;
        
    }
};