#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > g;
vector<int> p;

int find(int v) {
    if(v == p[v]) {
        return v;
    }else {
        return p[v] = find(p[v]);
    }
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        p[a] = b;
    }
}

int main() {
    int v, e, x, y, total = 0;
    cin >> v >> e >> x >> y;
    p.resize(v);
    int both = min(x, y);
    for(int i = 0; i < e; i++) {
        string type;
        int u, v, c;
        cin >> type >> u >> v >> c;
        u--; v--;
        if(type == "big") {
            c *= x;
        }else if(type == "small") {
            c *= y;
        }else {
            c *= both;
        }
        g.push_back(make_pair(c, make_pair(u, v)));
    }

    sort(g.begin(), g.end());

    for(int i = 0; i < v; i++) {
        p[i] = i;
    }
    for(int i = 0; i < g.size(); i++) {
        int u = g[i].second.first;
        int v = g[i].second.second;
        int cost = g[i].first;
        if(find(u) != find(v)) {
            total += cost;
            unite(u, v);
        }
    }
    cout << total;
    return 0;
}

// run id = 1210