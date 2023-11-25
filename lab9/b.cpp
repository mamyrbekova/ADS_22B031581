#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> computeLps(string s) {
    vector<int> pi(s.length());
    for(int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j- 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(string txt, string pattern) {
    vector<int> ans;

    string concat = pattern + '#' + txt;
    vector<int> pi = computeLps(concat);
    for(int i = pattern.size() + 1; i < concat.size(); i++) {
        if(pi[i] == pattern.size()) {
            ans.push_back(i - 2 * pattern.size());
        }
    }
    return ans;
}

int main() {
    string s, t;
    int k;
    cin >> s >> k >> t;
    vector<int> v = kmp(t, s);
    int n = v.size();
    if(k <= n) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    return 0;
}

// run id = 1881