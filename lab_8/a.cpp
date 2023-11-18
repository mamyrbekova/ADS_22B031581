#include <iostream>
#include <cmath>
#include <map>

int MOD = 1e9+7;
using namespace std;

string hashCode(string s, int MOD = 1e9 + 7, int q = 11){
    long long p = 1; long long ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans = (ans + ((s[i] - 47) * p) % MOD) % MOD;
        p = (p * q) % MOD;
    }
    return to_string(ans);
}

int main() {
    int n, cnt = 0;
    cin >> n;
    string a[2*n];
    map<string, string> hashmap;
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];
        hashmap.insert(pair(a[i], hashCode(a[i])));
    }
    for(int i = 0; i < 2*n; i++) {
        string temp = hashCode(a[i]);
        if(hashmap.find(temp) != hashmap.end()) {
            cout << "Hash of string \"" << a[i] << "\" is " << temp << endl;
            cnt++;
        }
        if(cnt == n)
            break;
    }
}
//run id = 8110