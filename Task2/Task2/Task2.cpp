#include <iostream>
#include <windows.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int arr[10];
    int choice;
    cout << "Введіть 10 чисел:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Оберіть алгоритм сортування:" << endl;
    cout << "1 - Сортування вибором" << endl;
    cout << "2 - Сортування злиттям" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;
    if (choice == 1)
    {
        selectionSort(arr, 10);
    }
    else if (choice == 2)
    {
        mergeSort(arr, 0, 9);
    }
    cout << "Відсортований масив: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}