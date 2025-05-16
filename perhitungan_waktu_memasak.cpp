#include <iostream>
using namespace std;

// Fungsi untuk waktu oven
int ovenTime() {
    return 40;
}
// Fungsi untuk sisa waktu oven
int remainingOvenTime(int actualMinutes) {
    return ovenTime() - actualMinutes;
}
// Fungsi waktu persiapan (2 menit per layer)
int preparationTime(int layers) {
    return layers * 2;
}
// Fungsi menghitung total waktu kerja:persiapan + waktu oven
int elapsedTime(int layers, int actualMinutes) {
    return preparationTime(layers) + actualMinutes;
}
// Uji program di fungsi main
int main() {
    cout << "Waktu oven: " << ovenTime() << " menit \n";
    cout << "Sisa waktu oven (30 menit): " << remainingOvenTime(30) << "\n";
    cout << "Waktu persiapan (2 layer): " << preparationTime(2) << " menit \n";
     cout << "Total waktu kerja: " << elapsedTime(3, 20) << " menit \n";

    return 0;
    
}