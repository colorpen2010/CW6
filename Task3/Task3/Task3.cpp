#include <iostream>
#include <windows.h>
using namespace std;

void quickSort(int arr[], int left, int right){
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}
int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout << "Ввiдiть розмір масиву: ";
    cin >> n;
    int arr[100];
    cout << "Ввiдiть елементи масиву: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Вiдсортований масив: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}