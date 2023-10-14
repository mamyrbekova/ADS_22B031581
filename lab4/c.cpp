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
  private:
    Node *root;

    void _inorder(Node *node) {
        if (!node)
            return;
        _inorder(node->left);
        cout << node->val << " ";
        _inorder(node->right);
    }

    void _preorder(Node *node) {
        if (!node)
            return;
        cout << node->val << " ";
        _preorder(node->left);
        _preorder(node->right);
    }

    void _postorder(Node *node) {
        if (!node)
            return;
        _postorder(node->left);
        _postorder(node->right);
        cout << node->val << " ";
    }

    Node *_insert(Node *cur, int val) {
        if (!cur) {
            return new Node(val);
        }
        if (val > cur->val) {
            cur->right = _insert(cur->right, val);
        } else if (val < cur->val) {
            cur->left = _insert(cur->left, val);
        }

        return cur; // необязательно
    }



    int _getSize(Node *node) {
        if (!node)
            return 0;
        return _getSize(node->left) + _getSize(node->right) + 1;
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
    BST() { this->root = nullptr; }


    void insert(int val) {
        Node *newNode = _insert(root, val);
        
        if (root == nullptr)
            root = newNode;
    }


    Node *search(int target) { return _search(root, target); }

    Node *getRoot() { return root; }

    int getSize() { return _getSize(root); }

    void solve(Node *node, int k) {
        Node *target = _search(node, k); 
        _preorder(target);            
    }
};

int main() {

    BST bst;
    int n, k;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        bst.insert(x);
    }

    cin >> k;

    bst.solve(bst.getRoot(), k);

    return 0;
}

//run id = 919	