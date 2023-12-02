#include <iostream>

using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;
    long long matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    while (q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;

        if (matrix[a][b] && matrix[a][c] && matrix[b][c])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

// run id = 6451