#include <iostream>
#include <cmath>
using namespace std;

int sum[500];
struct Node {
    int key;
    Node* left;
    Node* right;
    Node () {
        left = NULL;
        right = NULL;
    }
    Node(int key) {
        this->key = key;
    }
};

void insert(Node* &root, int key) {
    if(root == NULL) {
        root = new Node(key);
        return;
    }
    if(root->key > key) {
        insert(root->left, key);
    }else {
        insert(root->right, key);
    }
}

void printt(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int getHeight(Node* root) {
    if(root->left == NULL && root->right == NULL) {
        return 0;
    }
    int left = 0;
    if(root->left != NULL) {
        left = getHeight(root->left);
    }
    int right = 0;
    if(root->right != NULL) {
        right = getHeight(root->right);
    }

    return(max(left, right) + 1);
}

void sums(Node *root, int level, int sum[]) {
    if(root == NULL) {
        return;
    }
    sum[level] += root->key;
    sums(root->left, level + 1, sum);
    sums(root->right, level + 1, sum);
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + max(left_height, right_height);
    }
}

int main() {
    Node *root = new Node();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        insert(root, k);
    }
    int level = getHeight(root);

    cout << getHeight(root);
    sums(root, 0, sum);
    for(int i = 0; i <= level; i++) {
        cout << sum[i];
    }
}

//run id = 2039