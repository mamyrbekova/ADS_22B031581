6400#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;
    int a[100005];
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(!v.empty() && v.back() > a[i]) {
            v.pop_back();
        }
        if(v.empty()) {
            cout << "-1" << " ";
        }else {
            cout << v.back() << " ";
        }
        v.push_back(a[i]);
    }
}
// run id = 6400
