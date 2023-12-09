#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <ctime>
#include <list>

using namespace std;

long long n, m, a, b, c;
long long ar[1100][1100];
long long par[600];

long long find(long long x){
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(long long a, long long b){
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rand()&1) swap(a, b);
    par[a] = b;
    return true;
}

int main(){
    cin >> n;
    for(long long i = 0; i < n; i++) par[i] = i;
    vector<pair<long long, pair<long long, long long> > > edges;
     for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < n; j++) {
        cin >> ar[i][j];
        if (!ar[i][j]) merge(i, j);
        else edges.push_back(make_pair(ar[i][j], make_pair(i, j)));
        }
    }
    sort(edges.begin(), edges.end());
    long long ans = 0;
    for(auto i : edges){
        if (merge(i.second.first,i.second.second)) ans += i.first;
    }
    cout << ans;


    return 0;
}

//run id = 1212
