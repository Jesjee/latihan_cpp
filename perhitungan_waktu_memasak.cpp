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
int elapsedTime(int layers, int actualMinutes