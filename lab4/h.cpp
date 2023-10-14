#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BST {
    BST() {
        this->root = nullptr;
    }

    BST(Node *root) {
        this->root = root;
    }
    
private:
    Node *root;


    Node *_insert(Node *cur, int val) {
        if (!cur) {
            return new Node(val);
        }
        if (val > cur->val) {
            cur->right = _insert(cur->right, val);
        } else if (val < cur->val) {
            cur->left = _insert(cur->left, val);
        }

        return cur; 
    }

    Node *_search(Node *cur, int target) {
        if (!cur)
            return nullptr;
        if (cur->val == target)
            return cur;
        if (cur->val > target)
            return _search(cur->left, target);
        return _search(cur->right, target);
    }

  public:
    
     Node *getRoot() {
        return root;
    }

    void insert(int val) {
        Node *newNode = _insert(root, val);
        if (root == nullptr)
            root = newNode;
    }

    void reverseInorder(Node *node, int &s) {
        if (!node)
            return;
        reverseInorder(node->right, s);

        cout << node->val + s << " ";
        s += node->val;

        reverseInorder(node->left, s);
    }
};

int main() {
    BST bst;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        bst.insert(x);
    }

    int s = 0;
    bst.reverseInorder(bst.getRoot(), s);

    return 0;
}
// run id = 2023