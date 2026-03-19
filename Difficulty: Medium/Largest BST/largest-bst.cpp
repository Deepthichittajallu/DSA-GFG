class Solution {
  public:
    
    class BSTInfo {
      public:
        int mini;
        int maxi;
        int mxSz;

        BSTInfo(int mn, int mx, int sz) {
            mini = mn;
            maxi = mx;
            mxSz = sz;
        }
    };

    BSTInfo solve(Node *root) {
        if (!root)
            return BSTInfo(INT_MAX, INT_MIN, 0);

        BSTInfo left = solve(root->left);
        BSTInfo right = solve(root->right);

        // If current subtree is BST
        if (left.maxi < root->data && right.mini > root->data) {
            return BSTInfo(
                min(left.mini, root->data),
                max(right.maxi, root->data),
                1 + left.mxSz + right.mxSz
            );
        }

        // Not a BST
        return BSTInfo(INT_MIN, INT_MAX, max(left.mxSz, right.mxSz));
    }

    int largestBst(Node *root) {
        return solve(root).mxSz;
    }
};