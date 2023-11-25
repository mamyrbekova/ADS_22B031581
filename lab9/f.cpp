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

vector<int> KMP(string txt, string pattern) {
	vector<int> res;
	string concat = pattern + '#' + txt;
	vector<int> pi = computeLps(concat);
	for (int i = pattern.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pattern.size()) {
			res.push_back(i - 2 * pattern.size());
		}
	}
	return res;
}

int main() {
	string s, t;
	cin >> s >> t;
	vector<int> v = KMP(s, t);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] + 1 << " ";
	}
	
	return 0;
}

// run id =3131