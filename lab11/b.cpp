#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    int ar[n];
    int minmin = 1e6;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        minmin = min(minmin, ar[i]);
        sum += ar[i];
    }
    sum -= minmin;
    cout << (n - 1) * minmin + sum;
    return 0;
}

// run id = 1205