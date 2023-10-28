#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& b, const vector<int>& an) {
    int i = 0;
    int j = 0;
    vector<int> merged;
    
    while (i < b.size() && j < an.size()) {
        if (b[i] <= an[j]) {
            merged.push_back(b[i]);
            i++;
        } else {
            merged.push_back(an[j]);
            j++;
        }
    }
    
    while (i < b.size()) {
        merged.push_back(b[i]);
        i++;
    }
    
    while (j < an.size()) {
        merged.push_back(an[j]);
        j++;
    }

    
    b = merged;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cin >> m;

    vector<int> an(m);

    for (int i = 0; i < m; i++) {
        cin >> an[i];
    }

    
    merge(b, an);

    for (int num : b) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}

// run id = 2510