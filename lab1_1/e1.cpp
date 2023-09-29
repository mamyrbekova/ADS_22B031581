#include <iostream>
#include <stack>
#include <deque>
#include <string>
using namespace std;

int main() {
    int b, n;
    int cnt = 0;
    deque<int> boris;
    deque<int> nursik;
    for(int i=0; i<5; i++) {
        cin >> b;
        boris.push_back(b); //1 3 
    }
    for(int i=0; i<5; i++) {
        cin >> n;
        nursik.push_back(n); //2 4 6 8 0 9
    }
    while(!boris.empty() && !nursik.empty()) {
        if(boris.front() == 0 && nursik.front() == 9) {
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
        else if(boris.front() == 9 && nursik.front() == 0) {
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
        else if(boris.front() > nursik.front()) {
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
        else if(boris.front() < nursik.front()) {
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
        }
        if(cnt >= 1000000) {
            cout << "blin nichya";
            break;
        }
        cnt++;
    }
    if(boris.empty()) {
        cout << "Nursik " << cnt;
    }
    else if(nursik.empty()) {
        cout << "Boris " << cnt;
    }
}

