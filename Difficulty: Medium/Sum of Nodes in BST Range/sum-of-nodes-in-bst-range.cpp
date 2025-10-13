/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        int sum = 0;
        if(root == nullptr)
        {
            return 0;
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
                if(node->data >= l && node -> data <= r)
                {
                    sum += (node->data);
                }
                if(node -> left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};
