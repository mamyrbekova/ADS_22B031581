#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isFeasible(const vector<int>& giftCounts, int capacity, int f) {
    int flights = 0;
    for (int count : giftCounts) {
        flights += (count + capacity - 1) / capacity; 
    }
    return flights <= f; 
}

int main() {
    int n, f;
    cin >> n >> f;

    vector<int> giftCounts(n);

    for (int i = 0; i < n; ++i) {
        cin >> giftCounts[i];
    }

    int left = 1; // Minimum bag capacity needed
    int right = *max_element(giftCounts.begin(), giftCounts.end()); // Maximum bag capacity needed

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isFeasible(giftCounts, mid, f)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}
//run id = 8271
