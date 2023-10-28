#include <cmath>
#include <iostream>
using namespace std;
  
int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; 
    int i = (left - 1);
  
    for (int j = left; j <= right - 1; j++) {

        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}
  
void quickSort(int arr[], int left, int right)
{
    if (left < right) {

        int pivotIndex = partition(arr, left, right);
  

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}
  
void print(int arr[], int size) {
    
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
        
    cout << endl;
}
  
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);

    int absDiff = 999999;

    for (int i = 0; i < n - 1; i++) {
       if (arr[i + 1] - arr[i] < absDiff) {
            absDiff = abs(arr[i + 1] - arr[i]);
       }
    }

    for (int i = 0; i < n - 1; i++) {
       if (arr[i + 1] - arr[i] == absDiff) {
            cout << arr[i] << " " << arr[i + 1] <<" ";
       }
    }

    return 0;
}
