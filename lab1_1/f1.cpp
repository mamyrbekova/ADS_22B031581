#include <iostream>
using namespace std;
 
bool isPrime(int n){
    if(n < 2) return false;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool nthPrime(int num) {
    if (num <= 0) return -1;
    int cnt = 0;
    int prCnt = 2;

    while (true) {
        if(isPrime(prCnt)) {
            cnt++;
            if(cnt == num) {
                return prCnt;
            }
        }
        prCnt++;
           
    }
}

int main() {
    int n;
    cin >> n;
    int res = nthPrime(n);
    if(res != -1) {
        cout << res << endl;
    }
    return 0;
}
// run id = 2662
