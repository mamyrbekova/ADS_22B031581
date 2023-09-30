#include <iostream>
#include <map>
using namespace std;

struct Node{
    int value;
    Node *next;

    Node(int newVal) {
        this->value = newVal;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* cur = head;
    while(cur != NULL) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}

void nearestNum(Node* head, int nearest) {
    Node* cur = head;
    int res = 0;
    int index = 0;

    int min = abs(nearest - head->value);
    while(cur != NULL) {
        if(min > abs(nearest - cur->value)) {
            min = abs(nearest - cur->value);
            res = index;
        }
        cur = cur->next;
        index++;
    }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    Node *head;
    Node *cur;
    Node *a;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if(i == 0) {
            head = new Node(val);
            cur = head;
        }else {
            a = new Node(val);
            cur->next = a;
            cur = cur->next;
        }
    }
    int nearest;
    cin >> nearest;
    nearestNum(head, nearest);

}

// run id : 4503