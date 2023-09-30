#include <iostream>
#include <map>
using namespace std;

map <int, int> a;
int cnt = 0;

struct Node {
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    } 
};

void mode(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        a[cur->val]++;
        cnt = max(cnt, a[cur->val]);
        cur = cur->next;
    }
}

void print(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main () {
    int n; cin >>n;
    Node *head;
    Node *cur;
    for (int i = 0; i < n; i++) {
        int val;cin >>val;
        if (i == 0) {
            head = new Node(val);
            cur = head;
        } else {
            cur -> next = new Node(val);
            cur = cur -> next;
        }
    }
    mode(head);
    map <int, int>::reverse_iterator it = a.rbegin();
    for(; it != a.rend(); it++) {
        if(it->second == cnt) {
            cout << it->first<< " ";
        }
    }
}

//run id = 5735