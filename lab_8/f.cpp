#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long p = 31;
    long long n =  s.length();
    unordered_set <long long> hashSet;
    for (long long i=0; i<n; i++){
        string temp = "";
        long long h = 0;
        for (long long j = i; j < n; j++){
            h = h * p + s[j];
            hashSet.insert(h);
        }
    }
    cout << hashSet.size();

    return 0;
}

// run id = 8113