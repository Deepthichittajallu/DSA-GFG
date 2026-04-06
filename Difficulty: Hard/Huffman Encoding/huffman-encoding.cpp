class Solution {
  public:
  
    struct Node {
        int data;
        int id;
        Node *left, *right;
        
        Node(int d, int i) {
            data = d;
            id = i;
            left = right = NULL;
        }
    };
    
    struct compare {
        bool operator()(Node* l, Node* r) {
            if (l->data == r->data)
                return l->id > r->id;
            return l->data > r->data;
        }
    };
    
    void preorder(Node* root, string str, vector<string>& ans) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            ans.push_back(str);
            return;
        }
        
        preorder(root->left, str + "0", ans);
        preorder(root->right, str + "1", ans);
    }
    
    vector<string> huffmanCodes(string &s, vector<int> f) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    for (int i = 0; i < f.size(); i++) {
        pq.push(new Node(f[i], i));
    }
    
    // 🔥 EDGE CASE: only one character
    if (pq.size() == 1) {
        return {"0"};
    }
    
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        
        int newId = min(left->id, right->id);
        Node* parent = new Node(left->data + right->data, newId);
        
        parent->left = left;
        parent->right = right;
        
        pq.push(parent);
    }
    
    vector<string> ans;
    preorder(pq.top(), "", ans);
    
    return ans;
}};