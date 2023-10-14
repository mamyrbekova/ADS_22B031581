#include <iostream>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int val) {
        this->key = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};


void insert(Node* &root, int key) {
    if (root == nullptr) 
    {
        root = new Node(key);
        return;
    }
    else if (root -> key > key) 
    {
        insert(root -> left, key);
    }
    else 
    {
        insert(root -> right, key);
    }
}

bool available(Node *root, string key) {
    for (int i = 0; i < key.length(); i++){
        if (key[i] == 'L') {
            root = root -> left;
            if(root == nullptr) return false;
        }
        else{
            root = root -> right;
            if(root == nullptr) return false;
        }
    }
    return true;
}

int main() {
    int n; cin >> n;
    int size; cin >> size; 
    
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }

    while(size--) {
        string c; cin >> c;
        if(available(root, c)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
// run id = 3202