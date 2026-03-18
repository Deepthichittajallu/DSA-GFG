/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/
int distCandyUtil(Node* root, int& ans) {
  
    if (root == nullptr)
        return 0;
    int l = distCandyUtil(root->left, ans);
    int r = distCandyUtil(root->right, ans);
    ans += abs(l) + abs(r);
    return root->data + l + r - 1;
}
class Solution {
  public:
    int distCandy(Node* root) {
        // code here
        int ans = 0;
        distCandyUtil(root, ans);
        return ans;
    }
};