#include <iostream>
#include <windows.h>
using namespace std;

void sortPart(int a[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void reversePart(int a[], int start, int end) {
    end--;

    while (start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int a[9] = { 5, -2, 8, 3, 1, 6, 4, 9, 2 };
    double sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += a[i];
    }
    double average = sum / 9;
    cout << "Середнє арифметичне: " << average << endl;
    if (average > 0) {
        sortPart(a, 0, 6);
        reversePart(a, 6, 9);
    }
    else {
        sortPart(a, 0, 3);
        reversePart(a, 3, 9);
    }
    cout << "Результат:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << a[i] << " ";
    }
    return 0;
}