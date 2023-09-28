

#include <iostream>
#include <queue>

using namespace std;
int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;
    deque<int> q1, q2;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'K') {
            q1.push_back(i);
        }else {
            q2.push_back(i);
        }
    }

    while(!q1.empty() && !q2.empty()) {
        int first = q1.front();
        q1.pop_front();
        int second = q2.front();
        q2.pop_front();
        if (first < second) {
            q1.push_back(first + n);
        }else {
            q2.push_back(second + n);
        }
    }

    if(!q1.empty()){
        cout << "KATSURAGI";
    }else {
        cout << "SAKAYANAGI";
    }

}