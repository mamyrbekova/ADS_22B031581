#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &s) {
    stack<char> charStack;

    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (charStack.empty()) {
            charStack.push(c);
        } else {
            char topChar = charStack.top();
            if (topChar == c) {
                charStack.pop();
            } else {
                charStack.push(c);  
            }
        }
    }

    return charStack.empty();
}

int main() {
    string input;
    cin >> input;

    if (isBalanced(input)) {
        cout << "The string is balanced." << endl;
    } else {
        cout << "The string is not balanced." << endl;
    }

    return 0;
}
// run id = 4287
