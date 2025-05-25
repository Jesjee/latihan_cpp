#include <iostream>
using namespace std;

struct  Mahasiswa {
    string NIM;
    string Nama;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;

void tambahMahasiswa(string nim, string nama) {
    Mahasiswa* baru = new Mahasiswa{nim, nama, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void hapusMahasiswa(string nim) {
    Mahasiswa* temp = head;
    Mahasiswa* prev = nullptr;

    while (temp != nullptr && temp->NIM != nim) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }
    if (prev == nullptr) {
        head = temp->next; // Hapus dari awal
    } else {
        prev->next = temp->next; // Hapus dari tengah atau akhir
    }
    delete temp;
    cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus!" << endl;
}

void cetakMahasiswa() {
    cout << "Data Mahasiswa:\n";
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        cout << "NIM: " << temp->NIM << ", Nama: " << temp->Nama << endl;
        temp = temp->next;
    }
}
int main() {
    tambahMahasiswa("001", "Andi");
    tambahMahasiswa("002", "Budi");
    tambahMahasiswa("003", "Citra");

    cetakMahasiswa();

    hapusMahasiswa("002");

    cetakMahasiswa();

    return 0;
}
