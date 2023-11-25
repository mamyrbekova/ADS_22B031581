#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> computeLps(string s) {
    vector<int> pi(s.length());
    for(int i = 1; i < s.length(); i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
    string s, t;
    cin >> s >> t;
    vector<int> pi = computeLps(t);
    int i = 0;
    int j = 0;
    int n = s.size();
    int m = t.size();
    while(i < n) {
        while(j < m && s[(i + j) % n] == t[j]) {
            j++;
        }
        if(j == m) {
            cout << (i + j - 1) / n + 1;
            return 0;
        }
        j = pi[j];
        i += max(1, j - pi[j]);
    }
    cout << -1;
    return 0;
}

// run id = 1873