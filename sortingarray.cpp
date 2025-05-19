#include <iostream>
using namespace std;

int main() {
    int array[] = {5, 2, 9, 1, 3};
    int n = sizeof(array) / sizeof(array[0]);
    int* ptr = array;

    // Cetak array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    // Bubble sort menggunakan pointer arithmetic
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    
    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}