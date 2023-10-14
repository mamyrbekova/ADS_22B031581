#include <iostream>
#include <cmath>
using namespace std;

void binarySearch(int ar[], int l, int r) {
    if (l <= r) {
        int mid = l + (r - l) / 2;
        cout << ar[mid] << " ";
        binarySearch(ar, l, mid - 1);
        binarySearch(ar, mid + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    int size = pow(2, n) - 1;
    int ar[size];
    for (int i = 0; i < size; i++) {
        cin >> ar[i];
    }

    sort(ar, ar + size);

    binarySearch(ar, 0, size - 1);

    return 0;
}

//run id = 2031	