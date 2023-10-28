#include <iostream> 
using namespace std;

int partition(string &str, int left, int right)
{
    int pivot = str[right];
    int i = (left - 1);
  
    for (int j = left; j <= right - 1; j++) {

        if (str[j] < pivot) {
            i++; 
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[right]);
    return (i + 1);
}
  
void quickSort(string &str, int left, int right)
{
    if (left < right) {

        int pivotIndex = partition(str, left, right);
  
        quickSort(str, left, pivotIndex - 1);
        quickSort(str, pivotIndex + 1, right);
    }
}
  
int main()
{
    string str;
    cin >> str;

    quickSort(str, 0, str.size() - 1);
    cout << str;
    return 0;
}
//run id = 4518
