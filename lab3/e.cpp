#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, answer = -1;
    cin >> n >> k;
    vector<pair<int, int> > ar(n);
    for(int i = 0; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        ar[i] = make_pair(x, y);
    }
    int l = 0, r = 1e9 + 1;
    while(l + 1 < r) {
        int mid;
        mid  = l + (r - l) / 2;
        int sheeps = 0;
        for(int i = 0; i < n; i++) {
            if(mid >= ar[i].first && mid >= ar[i].second) {
                sheeps++;
            }
        }
        if(k <= sheeps) {
            r = mid;
            answer = mid;
        }else {
            l = mid;
        }
    }

    cout << answer;
    return 0;
}

// run id = 1966