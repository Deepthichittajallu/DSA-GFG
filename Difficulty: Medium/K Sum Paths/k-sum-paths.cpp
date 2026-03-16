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
    
    int cnt = 0;
    unordered_map<int,int>m;
    void fun(Node* root,int k,int sum) {
        
        if(root == NULL) return;
        
        sum += (root->data);
        
        int need = sum - k;
        if(m[need] > 0) cnt += m[need];
        m[sum]++;
        fun(root->left,k,sum);
        fun(root->right,k,sum);
        m[sum]--;
    }
    
    int countAllPaths(Node *root, int k) {
        // code here
        m[0]++;
        fun(root,k,0);
        
        return cnt;
    }
};