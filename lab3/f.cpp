#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int searrch(vector<int> a, int power) {
    int l = 0, r = a.size() - 1;
    while(l <= r) {
        int mid = l + (r - l)/ 2;
        if(power >= a[mid]) {
            l = mid + 1;
        }else if(power <= a[mid]) {
            r = mid - 1;
        }else if(power == a[mid]) {
            return l;
        }
    }
    return l;
} 

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int round;
    cin >> round;
    int power[round];

    for(int i = 0; i < round; i++) {
        int x;
        cin >> x;
        int answer = searrch(v, x);
        int sum = 0;
        for(int j = 0; j < answer; j++) {
            sum += v[j];
        }
        cout << answer << " " << sum << endl;
    }
    return 0;
}
// run id = 2544
