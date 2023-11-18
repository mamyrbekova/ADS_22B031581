#include <iostream>
#include <vector>
using namespace std;

unsigned long long p = 1;

char decrypt(long long x) {
    char c = (x / p) + 97;
    p *= 2;
    return c;
}

int main() {
    long long n;
    cin >> n;
    vector<unsigned long long> v;
    while (n--) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    for (long long i = 0; i < v.size(); i++) {
        if (i == 0) {
            cout << decrypt(v[i]);
        } else {
            cout << decrypt(v[i] - v[i - 1]);
        }
    }
    return 0;
}
// run id = 8112