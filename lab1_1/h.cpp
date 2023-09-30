
#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;

    for(int i = 2; i < n / 2 + 1; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    if(isPrime(n) == true){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}

// run id = 1236
