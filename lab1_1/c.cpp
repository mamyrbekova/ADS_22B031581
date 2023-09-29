#include <iostream>
#include <stack>
using namespace std;

bool backspacee(string s, string t) {
    stack<char> s1;
    stack<char> t1;

    for(int i = 0; i < s.size(); i++) {
        s1.push(s[i]);
        if(s1.top() == '#') {
            s1.pop();
            if(!s1.empty()) {
                s1.pop();
            }
        }
    }

    for(int i = 0; i < t.size(); i++) {
        t1.push(t[i]);
        if(t1.top() == '#') {
            t1.pop();
            if(!t1.empty()) {
                t1.pop();
            }
        }
    }

    string a = "";
    string b = "";

    while(!s1.empty()){
           a += s1.top();
           s1.pop();
       }
    while(!t1.empty()){
           b += t1.top();
           t1.pop();
       }
    
    return a == b;

}

int main() {
    string s2;
    string t2;
    cin >> s2;
    cin >> t2;

    bool res = backspacee(s2, t2);

    if(res) {
        cout << "Yes";
    }else {
        cout << "No";
    }
    return 0;
}