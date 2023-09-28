#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n, t;
	cin >> t;
	while(t--) {
		cin >> n;
		deque <int> a;	
		a.push_back(n);
		for(int i = n - 1; i >= 1; i--){
			a.push_back(i);
			for(int j = 0; j <= i; j++){
				int b = a.back();
				a.push_front(b);
				a.pop_back();
			}
		}
		for(int i = 0; i < a.size(); i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		
	}
}




