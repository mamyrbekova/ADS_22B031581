#include <iostream>
#include <string>
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

int main() {
    int n; 
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char target; 
    cin >> target;

    quickSort(a, 0, n - 1);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > target) {
            cout << a[i];
            cnt++;
            return 0;
        }
    }
    if (cnt == 0) {
        cout << a[0];
    }
}

