#include <iostream>
using namespace std;    

int main() {
    // Deklarasi variabel suhu
    float celcius, fahrenheit;

    // Input suhu dalam Celcius
    cout << "Masukkan suhu dalam Celcius: ";
    cin >> celcius;

    // Konversi Celcius ke Fahrenheit
    fahrenheit = (celcius * 9 / 5) + 32;

    // Hasil konversi
    cout << celcius << "°C = " << fahrenheit << "°F" << endl;

    return 0;
       
}