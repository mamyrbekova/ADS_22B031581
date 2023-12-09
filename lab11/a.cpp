#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <ctime>
#include <list>

using namespace std;

long long n, m, a, b, c, x, y;
long long ar[200500];
long long p[200500];
long long le[200500];
long long ri[200500];

long long find(long long x){
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool merge(long long a, long long b){
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rand()&1) swap(a, b);
    p[a] = b;
    le[b] = min(le[a], le[b]);
    ri[b] = max(ri[a], ri[b]);
    return true;
}

int main(){
    cin >> n >> m;
    for(long long i = 0; i < (n); i++) p[i] = i, le[i] = i, ri[i] = i;
    vector<pair<long long, pair<long long, long long>>> edges;
    string s;
    for(long long i = 0; i < (m); i++){
        cin >> a >> b >> c; a--, b--;
        edges.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());
    long long ans = 0, mm = -1, cnt = 0;
    for(auto i : edges){
        if (cnt >= n-1) break;
        long long l = i.second.first, r = i.second.second, c = i.first;
        mm = l;
        for(long long i = l; i <= r; i++) {
            if (find(i) != i) {
                mm = find(i);
                break;
            }
        }
        if (le[mm] <= l && r <= ri[mm]) continue;
        else if (le[mm] <= r && r <= ri[mm]) r = le[mm];
        else if (le[mm] <= l && l <= ri[mm]) l = ri[mm];
        for(long long i = l; i <= r; i++){
            if (merge(mm, i)) {
                ans += c, cnt++;
            }
        }
    }
    cout << ans;


    return 0;
}

//run id = 2752