#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLps(string s) {
    vector<int> pi(s.size());

    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return pi;
}

int main() {
    string s;
    cin >> s; 

    vector <int> pi = computeLps(s);
    int cnt = 0;
    for (int i = 1; i < pi.size(); i++) {
        if(i % 2 == 0) {
            int k = i - pi[i - 1];
            if((i / k) % 2 == 0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}

// run id = 3180