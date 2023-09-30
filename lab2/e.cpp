#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

struct Node{
    string val;
    Node *next;

    Node(string val) {
        this->val = val;
        this->next = NULL;

    }
    Node () {}

};

void duplicate(Node* head) {
    Node *cur = head;
    Node *past = head;

    while(cur != NULL) {
        if(cur->val == past->val) {
            past->next = cur->next;
        }else {
            past->next = cur;
            past = past->next;
        }
        cur = cur->next;
    }
}

int count(Node* head) {
    Node* cur = head;
    int cnt = 0;
    while(cur != NULL) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

void push(Node** head_ref, string data) {
    Node* new_node = new Node();
    new_node->val = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void print(Node* head) {
    Node* cur = head;
    while(cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
}

int main() {
    int n;
    cin >> n;
    Node *head = NULL;
    string val;
    for(int i = 0; i < n; i++) {
        cin >> val;
        push(&head, val);

    }
    duplicate(head);
    cout << "All in all: " << count(head) << endl;
    cout << "Students: " << endl;
    print(head);
}

