#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int subarray(vector<int>& nums, int k) {
    int n = nums.size();
    int length = n + 1;
    vector<int> sum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }

    for (int i = 0; i < n; i++) {
        int target = k + sum[i];
        int left = i + 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] >= target) {
                length = min(length, mid - i);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return length <= n ? length : 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = subarray(nums, k);
    cout << result << endl;

    return 0;
}

// run id = 3786