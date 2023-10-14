
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    int duplicate;
    Node (int key) {
        this -> val = key;
        this -> left = nullptr;
        this -> right = nullptr;
        this -> duplicate = 1;
    }
};



Node* add(Node* root, int key) {
	if (root == nullptr) {
		return new Node(key);
	} else if(root->val == key) {
        root->duplicate++;
    }
    else if (root->val > key) {
		if (root->left == nullptr) {
			root->left = new Node(key);
		} else {
			root->left = add(root->left, key);
		}
	} else if (root->val < key) {
		if (root->right == nullptr) {
			root->right = new Node(key);
		} else {
			root->right = add(root->right, key);
		}
	} 
	return root;
}
Node* getMin(Node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* find (Node * root, int key) {
	if (root == nullptr) {
		return nullptr;
	} else if (root->val == key) {
		return root;
	} else if (root->val < key) {
		return find(root->right, key);
	} else {
		return find(root->left, key);
	}
}

Node *remove(Node * root, int key) {
    if (root == nullptr) {
        return nullptr; 
    }
    else if (root ->val > key) {
        root -> left = remove(root -> left, key);
        return root;
    }
    else if (root -> val < key) {
        root -> right = remove(root -> right, key);
        return root;
    }
    else if (root -> val == key) {
        if (root -> duplicate == 0)  {
            if (root -> left == nullptr && root -> right == nullptr) {
                delete root;
                return nullptr;
            } else if (root -> right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root -> left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;      
            } else {
                Node* temp = getMin(root->right);
                root->val = temp->val;
                root->right = remove(root->right, temp->val);
                return root;
            }
        }  
        else root->duplicate--;
        return root;
    }
    return nullptr;
}

void solution (Node* &root, int val, string s) {
    if (s == "insert") {
        root = add(root, val);
    } else if (s == "delete") {
        root = remove(root, val);
    } else if (s == "cnt") {
        Node *finded = find(root, val);
        if (finded == nullptr) cout << 0 << "\n";
        else cout << finded->duplicate << "\n";
    }

}

int main () {
    int n;
    cin >> n;
    Node *root = nullptr;

    for (int i = 0; i < n; i++) {
        string s;
        int key;
        cin >> s >> key;

        solution(root, key, s);
    }
}

// run id = 3642