#include <cmath>
#include <iostream>
using namespace std;
  
int partition(int a[], int left, int right){
    int i = left - 1;
    int pivot = right;
    for(int j = left; j < right; j++){
        if(a[j] > a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);

    return i+1;
}

void quickSort(int a[], int left, int right){
    if(left < right){
        int pivot = partition(a, left, right);
    
        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}


  
void print(int arr[], int size) {
    for (int i = 0; i < size; i++){
         cout << arr[i] << " ";
    }
       
    cout << endl;
}


int main () {
    int row, column; 
    cin >> row; 
    cin >> column;
    int arr[row][column];
    int after[column][row];

    for (int i = 0; i < row; i++) {
        for (int j = 0 ; j < column; j++){
            cin >> arr[i][j];
            after[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < column; i++) {
        quickSort(after[i], 0, row - 1);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << after[j][i] << " ";
        }
        cout << endl;
    }
}
// run id = 4442
