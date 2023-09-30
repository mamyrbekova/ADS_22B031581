#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;


int main() {   
    bool flag = true;
    deque <int> dq;
    while (flag)
    {
        string s, num;
        getline(cin, s);
        char sign = s[0];

        if (s.empty())
        {
            continue;
        }
        if (sign == '*')
        {
            if (dq.empty()) 
            { 
                cout << "error" << endl;
                continue; 
            }
            else
            {
                if (dq.size() == 1)
                {
                    cout << dq.front() * 2 << endl;
                    dq.pop_front();
                }
                else if (dq.size() > 1)
                {
                    cout << dq.front() + dq.back() << endl;
                    dq.pop_front();
                    dq.pop_back();
                }

                continue;
            }
        }

        if (sign == '!') 
        {
            return 0;
        }

        for (int i = 2; i < s.size(); ++i)
        {
            num += s[i];
        }
        int n = stoi(num);

        if (sign == '+')
        {
            dq.push_front(n);
        }
        if (sign == '-')
        {
            dq.push_back(n);
        }


        
    }

    return 0;
}

// run id = 9740
