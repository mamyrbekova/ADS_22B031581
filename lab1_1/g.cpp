#include <iostream> 
#include <vector> 
using namespace std; 
 
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    for (int i = 2; i <= n / 2; i++){ 
        if (n % i == 0){ 
            return false; 
        } 
    } 
    return true; 
} 
vector<int> generatePrimes(int n) { 
    vector<bool> isPrime(n + 1, true); 
    vector<int> primes; 
 
    for (int p = 2; p * p <= n; p++) { 
        if (isPrime[p]) { 
            for (int i = p * p; i <= n; i += p) { 
                isPrime[i] = false; 
            } 
        } 
    } 
 
    for (int i = 2; i <= n; i++) { 
        if (isPrime[i]) { 
            primes.push_back(i); 
        } 
    } 
 
    return primes; 
} 
 
int main() { 
    int n; 
    cin >> n; 
    vector<int> primes = generatePrimes(100000); 
 
    vector<int> super; 
    for (int i = 0; i < primes.size() - 1; i++) { 
        if (isPrime(i + 1)) { 
            super.push_back(primes[i]); 
        } 
    } 
 
    if (n <= super.size()) { 
        cout << super[n - 1]; 
    } 
 
    return 0; 
}
// run id = 	5959
