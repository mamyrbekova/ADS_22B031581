#include <iostream>
#include <vector>
using namespace std;

int ssearch(int block[], int target, int size) {
    int  l = 0, r = size - 1;
    int res;
    while(l <= r) {
        int mid = l + (r - l) /2 ;
        if(target <= block[mid]) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n;
    int m;
    int sum = 0;
    cin >> n >> m;
    int block[n];
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        block[i] = sum;
    }

    while(m--) {
        int target;
        cin >> target;
        cout << ssearch(block, target, n) + 1 << "\n";
    }
}
//run id = 2563
