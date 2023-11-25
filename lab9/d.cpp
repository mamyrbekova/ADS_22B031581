#include <iostream>
#include <string> 
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int computeLps(string s) {
    int n = s.length();
    int lps[n];
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (s[i] != s[len]) {
            if (len != 0) {
                len = lps[len-1];
            }else {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    int res = lps[n-1];

    return (res > n/2) ? res/2 : res;
}


string tolower(string s) {
    for(int i = 0; i <= s.size(); i++) { 
        if(s[i] >= 65 && s[i] <= 92) {
            s[i] = s[i] + 32;
        }
    }
    return s;
}


int main() {
    string city;
    cin >> city;
    int n;
    cin >> n;
    int max = -1;
    unordered_map<string, int> map1;
    vector <string> map2;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        string res = tolower(x) + "#" + tolower(city);
        int ans = computeLps(res);
        if(ans >= max){
            if(ans == 0) continue;
            max = ans;
            map2.push_back(x);
        }
        map1[x] = ans;          
    }
    int cnt = 0;
    for (int i = 0; i < map2.size(); i++) {
        if(computeLps(tolower(map2[i]) + "#" + tolower(city)) == max) {
            cnt++;
        }
    }
    if(cnt == 0) {
        cout << 0;
        return 0;
    }
    cout << cnt << endl;

    for (int i = 0; i < map2.size(); i++) {
        if(computeLps(tolower(map2[i]) + "#" + tolower(city)) == max) {
            cout << map2[i] << endl;
        }
    }
}

// run id = 3064