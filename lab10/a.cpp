#include <iostream>
#include <queue>

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    queue<pair<int,int>> q;
    int s = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                q.push(make_pair(i,j));


            }
            if(arr[i][j] ==1 ) {
                s++;
            }
        }
    }
    if(s == 0){
        cout << 0;
        return 0;
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        vector<pair<int,int>>v;
        if(x > 0) v.push_back(make_pair(x-1,y));
        if(x < (n-1)) v.push_back(make_pair(x+1, y));
        if(y > 0) v.push_back(make_pair(x, y-1));
        if(y < (m-1)) v.push_back(make_pair(x, y+1));
        for(auto i : v){

            int x1 = i.first;
            int y1 = i.second;
            if(arr[x1][y1] == 1 ){
                    s--;

                arr[x1][y1] = 2 *((arr[x][y]/2) + 1);
                if(s == 0){
                cout<<(arr[x1][y1]/2) - 1;
                return 0;
            }
                q.push(make_pair(x1, y1));
            }
        }

    }
    cout << -1;

    return 0;
}

// run id = 6322
