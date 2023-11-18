#include <iostream>
#include <vector>
using namespace std;

long long hashFunc(string s) {
    long long MOD = 1e9 + 7;
    long long X = 31;
    long long ans = 0;
    long long newX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * newX % MOD;
        ans = (ans + curHash) % MOD;
        newX = (newX * X) % MOD;
    }
    return ans;
}

vector<long long> search(string s) {
    vector<long long> hashes(s.size());
    long long MOD = 1e9 + 7;
    long long X = 31;
    long long newX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * newX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        newX = (newX * X) % MOD;
    }
    return hashes;
}

void rabinKarp(string s, string t, vector <size_t> &vec) {
    long long MOD = 1e9 + 7;
    long long X = 31;
    long long smallHash = hashFunc(t);
    vector<int> res;
    vector<long long> hashes = search(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0) {
            hashDif -= hashes[i - 1];
        }
        if (hashDif < 0) {
            hashDif += MOD;
        }
        if (i != 0) {
            smallHash = (smallHash * X) % MOD;
        }
        if (smallHash == hashDif) {
            for (int j = i; j < i + t.size(); j++){
                vec[j]++;
            }
        }
    }
}


int main() {

    string s;
    cin >> s;
    vector<size_t> vec(s.size(), 0);
    long long n; cin >> n;
    for (int i = 0; i < n; i++) {
        string patt; cin >> patt;
        rabinKarp(s, patt, vec);
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES" << endl;
}

//runid = 3975