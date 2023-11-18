#include <iostream>
using namespace std;

int p = 31;

int hashFunc(string s){
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++){
        ans = ans * p + s[i];
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        l-=1;
        r -= 1;
        string temp = "";
        for (int j = l; j <= r; j++){
            temp += s[j];
        }
        int xS = s.length();
        int tempS = temp.length();

        int tempHash = hashFunc(temp);
        int xHash = hashFunc(s.substr(0, tempS));
        int cnt = 0;

        int pm = 1;
        for (int j = 0; j < tempS - 1; j++){
            pm = pm * p;
        }

        for (int j = 0; j <= xS - tempS; j++){
            if (tempHash == xHash){
                cnt++;
            }
            if (j < xS-tempS){
                xHash = (xHash - pm * s[j]) * p + s[j+tempS];
            }
        }
        cout << cnt << endl;
    }
}
// run id = 8119