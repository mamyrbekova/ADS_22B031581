#include <iostream>
#include <vector>
using namespace std;


string search(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;

    while(l <= r) {
        int mid  = l + (r - l) / 2;
        if(arr[mid] == x) {
            return "Yes";
        }else if(arr[mid] < x) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    return "No";
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    cout << search(arr, x) << endl;
    return 0;


}

// run id = 2167