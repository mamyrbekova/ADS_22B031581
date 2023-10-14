#include <iostream>

int cnt = 0;

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node () {
        left = nullptr;
        right = nullptr;
    }
    Node (int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node* &root, int key) {
    if (root == nullptr) 
    {
        root = new Node(key);
        return;
    }

    if (root -> key > key) 
    {
        insert(root -> left, key);
    }

    else 
    {
        insert(root -> right, key);
    }
}

void check(Node* root) {
    if (root == nullptr) return;
    if (root -> left != nullptr && root -> right != nullptr) {
        cnt++;
    }
    check(root -> left);
    check(root -> right);
}


int main () {
    Node *root = new Node();
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        insert(root, x);
    }

    check(root);
    cout << cnt;
}
// run id = 2151