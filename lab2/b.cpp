#include <iostream>
using namespace std;

struct Node {
    string word;
    Node* next;

    Node() {}

    Node(string word) {
        this->word = word;
        this->next = NULL;
    }
};

Node* rotatee(Node* head, int k) {
    Node *cur = head;
    Node *tail;
    while(cur->next != NULL) {
        cur = cur->next;
        tail = cur;
    }
    while(k--) {
        Node *a = head->next;
        tail->next = head;
        head->next = NULL;
        head = a;
        tail = tail->next;
    }
    return head;
}

void print(Node* head) {
    Node *cur = head;
    while(cur != NULL) {
        cout << cur->word << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    Node* head;
    Node* cur;
    for(int i = 0; i < n; i++) {
        string wrd;
        cin >> wrd;
        if(i == 0) {
            head = new Node(wrd);
            cur = head;

        }   else {
            cur->next = new Node(wrd);
            cur = cur->next;
        } 
    }

    head = rotatee(head, k);
    print(head);

}

//run id = 4533
