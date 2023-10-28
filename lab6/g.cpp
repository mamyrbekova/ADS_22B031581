#include <iostream>
#include <map>
#include <vector>
using namespace std;
int partition(char arr[], int left, int right)
{
    int pivot = arr[right]; 
    int i= (left - 1);
  
    for (int j = left; j <= right - 1; j++) {

        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}
  
void quickSort(char arr[], int left, int right)
{
    if (left < right) {

        int pivotIndex = partition(arr, left, right);
  

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}
  
void print(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    map<string,string> m;
    map<string, string>:: iterator it;
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        string newNickname, oldNickname;
        cin >> newNickname; 
        cin >> oldNickname;

        if (m.empty()) {
            m[newNickname] = oldNickname;
        }

        if(!m.empty()){
            for(it = m.begin(); it != m.end(); it++){
                if(newNickname == it->second){
                    m[it->first] = oldNickname;
                    m.erase(newNickname);
                    break;
                }
                else{
                    m[newNickname] = oldNickname;
                }
            }
        }
    }
    
    cout << m.size() << endl;
 
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}
// run id = 4739
