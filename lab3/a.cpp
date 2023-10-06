#include <iostream> 
 
using namespace std; 
 
int snake[800][800]; 
 
void seearch(int target, int n, int m) { 
    for (int i = 0; i < n; i++) { 
        int l = 0; int r = m - 1; 
        int mid; 
        if (i % 2 == 0) { 
            while (l <= r) { 
                mid = l + (r - l)/ 2; 
                if (target == snake[i][mid]) { 
                    cout << i << " " << mid << endl; 
                    return; 
                } else if (target > snake[i][mid]) { 
                    r = mid - 1;             
 
                } else if (target < snake[i][mid]) { 
                    l = mid + 1; 
                } 
            } 
        } else { 
            while (l <= r) { 
                mid = l + (r - l)/ 2; 
                if (target == snake[i][mid]) { 
                    cout << i << " " << mid << endl; 
                    return; 
                } else if (target > snake[i][mid]) { 
                    l = mid + 1;     
 
                } else if (target < snake[i][mid]) { 
                    r = mid - 1;         
                } 
            } 
        } 
    } 
    cout << -1 << endl; 
} 
 
 
 
int main () { 
 
    int n, m, size; 
 
    cin >> size; 
    int a[size]; 
    for (int i = 0; i < size; i++) { 
        cin >> a[i]; 
    } 
 
    cin >> n >> m;     
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cin >> snake[i][j]; 
        } 
    } 
    for (int i = 0; i < size; i++) { 
        int target = a[i]; 
        seearch(target, n, m); 
    } 

}

// run id = 2183