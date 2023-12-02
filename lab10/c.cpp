#include <iostream>
#include <queue>

using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    deque<int> v;
    while(b != a){
        v.push_front(b);
        if(b % 2 != 0 or b < a){
            b += 1;
        }else{
            b /= 2;
        }
    }
    cout << v.size() << endl;
    for(auto i : v){
        cout << i << " ";
    }

    return 0;
}

// run id = 6375