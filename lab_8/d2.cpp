#include <iostream>
#include <vector>
using namespace std;

int rabinKarp(string s, string t){
    int cnt = 0;

    long long h[s.size()];
    long long p[s.size()];
    p[0] = 1;
    long long q = 1e9 + 7;
    
    for(size_t i = 1; i < s.size(); i++){
        p[i] = (p[i - 1] * 31) % q;
    }

    for(size_t i  = 0; i < s.size(); i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }

    long long h_t = 0;
    for(size_t i = 0; i < t.size(); i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }

    for(size_t i = 0; i + t.size() - 1 < s.size(); i++){
        long long d = h[i + t.size() - 1];

        if(i > 0){
            d = (d - h[i - 1] + q) % q;
        }

        if(d == (h_t * p[i]) % q){
            cnt++;
        }
    }

    return cnt;

}


int main(){


    while(true){
        int n; cin >> n;
        if(n == 0){
            break;
        }

        string patterns[n];
        for(int i = 0; i < n; i++){
            cin >> patterns[i];
        }

        string text;
        cin >> text;

        int max = -1;
        vector<pair<string,int> > v;

        for(int i = 0; i < n; i++){
            int c = rabinKarp(text, patterns[i]);           
            if(c > max){
                max = c;
            }
            v.push_back(make_pair(patterns[i], c));
        }

        cout << max << endl;
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == max){
                cout << v[i].first << endl;
            }
        }
    }   
}
// run id = 4006