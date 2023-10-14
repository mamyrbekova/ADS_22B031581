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
    BST() { this->root = nullptr; }

    void insert(int val) {
        Node *newNode = _insert(root, val);
        if (root == nullptr)
            root = newNode;
    }

    Node *search(int target) { return _search(root, target); }

    Node *getRoot() { return root; }

    int getSize(Node *node) {
        if (!node)
            return 0;
        return getSize(node->left) + getSize(node->right) + 1;
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

    Node *target = bst.search(k); 
    cout << bst.getSize(target);  

    return 0;
}

//run id = 918