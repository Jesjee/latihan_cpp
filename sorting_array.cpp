#include <iostream>>
using namespace std;

// Fungsi untuk mencetak array menggunakan pointer
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " "; // Menggunakan pointer aritmetik
    }
    cout << endl;
}
