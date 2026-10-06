#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int a[10] = { 8, 3, 6, 1, 9, 2, 7, 5, 4, 0 };
    int gap = 10;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = gap * 10 / 13;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i + gap < 10; i++) {
            if (a[i] > a[i + gap]) {
                int temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                swapped = true;
            }
        }
    }
    cout << "Відсортований масив:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}