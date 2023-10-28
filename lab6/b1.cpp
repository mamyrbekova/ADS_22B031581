

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quicksort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int i = left, j = right;

        while (i < j) {
            while (i < j && arr[j] >= pivot)
                j--;
            if (i < j)
                arr[i++] = arr[j];

            while (i < j && arr[i] <= pivot)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }

        arr[i] = pivot;
        quicksort(arr, left, i - 1);
        quicksort(arr, i + 1, right);
    }
}

    vector<int> findCommonElements(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> commonElements;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            commonElements.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return commonElements;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    quicksort(arr1, 0, n - 1);
    quicksort(arr2, 0, m - 1);

    vector<int> commonElements = findCommonElements(arr1, arr2);

    for (int i = 0; i < commonElements.size(); i++) {
        cout << commonElements[i] << " ";
    }

    return 0;
}
// run id = 4118
