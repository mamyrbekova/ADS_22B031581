#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLps(string s) {
	vector<int> pi(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main() {
    string s;
    cin >> s;
    vector<int> v = computeLps(s);
    cout << s.size() - v[v.size() - 1];
    return 0;
}

// run id = 3168