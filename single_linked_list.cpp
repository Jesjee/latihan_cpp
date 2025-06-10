#include <iostream>
using namespace std;

// Deklarasi struktur node
typedef struct TNode {
    int data;
    TNode *next;
} TNode;

// Deklarasi variabel global
TNode *head, *tail;

// Fungsi inisialisasi
void init() {
    head = NULL;
    tail = NULL;
}

// Fungsi untuk mengecek apakah linked list kosong
int isEmpty() {
    if (tail == NULL) return 1;
    else return 0;
}

// Fungsi untuk menambahkan data di depan
void insertDepan(int databaru) {
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;
    
    if (isEmpty() == 1) {
        head = baru;
        tail = baru;
        head->next = head;
        tail->next = tail;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    cout << "Data masuk\n";
}

// Fungsi untuk menambahkan data di belakang
void insertBelakang(int databaru) {
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;
    
    if (isEmpty() == 1) {
        head = baru;
        tail = baru;
        head->next = head;
        tail->next = tail;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data masuk\n";
}

// Fungsi untuk menampilkan data
void tampil() {
    TNode *b;
    b = head;
    if (isEmpty() == 0) {
        do {
            cout << b->data << " ";
            b = b->next;
        } while (b != tail->next);
        cout << endl;
    } else {
        cout << "Masih kosong\n";
    }
}

// Fungsi untuk menghapus data di depan
void hapusDepan() {
    TNode *hapus;
    if (isEmpty() == 0) {
        int d;
        hapus = head;
        d = head->data;
        
        if (head != tail) {
            head = head->next;
            tail->next = head;
            delete hapus;
        } else {
            head = NULL;
            tail = NULL;
        }
        cout << d << " terhapus\n";
    } else {
        cout << "Masih kosong\n";
    }
}

// Fungsi untuk menghapus data di belakang
void hapusBelakang() {
    TNode *hapus, *bantu;
    if (isEmpty() == 0) {
        int d;
        if (head == tail) {
            d = tail->data;
            head = NULL;
            tail = NULL;
        } else {
            bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            hapus = tail;
            tail = bantu;
            d = hapus->data;
            tail->next = head;
            delete hapus;
        }
        cout << d << " terhapus\n";
    } else {
        cout << "Masih kosong\n";
    }
}

// Fungsi untuk menghapus semua elemen
void clear() {
    TNode *bantu, *hapus;
    if (isEmpty() == 0) {
        bantu = head;
        while (bantu->next != head) {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;
        tail = NULL;
    }
    cout << "Linked list telah dikosongkan\n";
}

// Fungsi untuk mencari data
void cariData(int data) {
    TNode *bantu;
    bantu = head;
    int found = 0, index = 0;
    
    if (isEmpty() == 0) {
        do {
            index++;
            if (bantu->data == data) {
                found = 1;
                break;
            }
            bantu = bantu->next;
        } while (bantu != tail->next);
        
        if (found == 1) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << index << endl;
        } else {
            cout << "Data tidak ditemukan\n";
        }
    } else {
        cout << "Linked list kosong\n";
    }
}

// Fungsi untuk menghapus data tertentu
void hapusData(int data) {
    if (isEmpty() == 1) {
        cout << "Linked list kosong\n";
        return;
    }
    
    TNode *hapus, *bantu;
    bantu = head;
    hapus = NULL;
    
    // Mencari node yang akan dihapus
    do {
        if (bantu->data == data) {
            hapus = bantu;
            break;
        }
        bantu = bantu->next;
    } while (bantu != tail->next);
    
    if (hapus == NULL) {
        cout << "Data tidak ditemukan\n";
        return;
    }
    
    // Jika node yang dihapus adalah head
    if (hapus == head) {
        hapusDepan();
        return;
    }
    
    // Jika node yang dihapus adalah tail
    if (hapus == tail) {
        hapusBelakang();
        return;
    }
    
    // Jika node di tengah
    bantu = head;
    while (bantu->next != hapus) {
        bantu = bantu->next;
    }
    
    bantu->next = hapus->next;
    cout << "Data " << hapus->data << " terhapus\n";
    delete hapus;
}

// Fungsi untuk menyisipkan data setelah node tertentu
void sisipSetelah(int data, int databaru) {
    if (isEmpty() == 1) {
        cout << "Linked list kosong\n";
        return;
    }
    
    TNode *baru, *bantu;
    bantu = head;
    
    // Cari node dengan data yang dimaksud
    do {
        if (bantu->data == data) {
            baru = new TNode;
            baru->data = databaru;
            baru->next = bantu->next;
            bantu->next = baru;
            
            // Jika disisipkan setelah tail, update tail
            if (bantu == tail) {
                tail = baru;
            }
            
            cout << "Data " << databaru << " berhasil disisipkan setelah " << data << endl;
            return;
        }
        bantu = bantu->next;
    } while (bantu != tail->next);
    
    cout << "Data " << data << " tidak ditemukan\n";
}

// Fungsi untuk menyisipkan data sebelum node tertentu
void sisipSebelum(int data, int databaru) {
    if (isEmpty() == 1) {
        cout << "Linked list kosong\n";
        return;
    }
    
    TNode *baru, *bantu, *sebelum;
    bantu = head;
    sebelum = NULL;
    
    // Cari node dengan data yang dimaksud
    do {
        if (bantu->data == data) {
            baru = new TNode;
            baru->data = databaru;
            
            // Jika disisipkan sebelum head
            if (bantu == head) {
                baru->next = head;
                head = baru;
                tail->next = head;
            } else {
                baru->next = bantu;
                sebelum->next = baru;
            }
            
            cout << "Data " << databaru << " berhasil disisipkan sebelum " << data << endl;
            return;
        }
        sebelum = bantu;
        bantu = bantu->next;
    } while (bantu != tail->next);
    
    cout << "Data " << data << " tidak ditemukan\n";
}

// Fungsi untuk menampilkan menu
void menu() {
    int pilihan, data, databaru;
    init();
    
    do {
        cout << "\n=== MENU SINGLE LINKED LIST CIRCULAR ===" << endl;
        cout << "1. Tambah Data di Depan" << endl;
        cout << "2. Tambah Data di Belakang" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Hapus Data di Depan" << endl;
        cout << "5. Hapus Data di Belakang" << endl;
        cout << "6. Cari Data" << endl;
        cout << "7. Hapus Data Tertentu" << endl;
        cout << "8. Sisipkan Data Setelah Node Tertentu" << endl;
        cout << "9. Sisipkan Data Sebelum Node Tertentu" << endl;
        cout << "10. Hapus Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertDepan(data);
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                insertBelakang(data);
                break;
            case 3:
                tampil();
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                cout << "Masukkan data yang dicari: ";
                cin >> data;
                cariData(data);
                break;
            case 7:
                cout << "Masukkan data yang akan dihapus: ";
                cin >> data;
                hapusData(data);
                break;
            case 8:
                cout << "Masukkan data node referensi: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> databaru;
                sisipSetelah(data, databaru);
                break;
            case 9:
                cout << "Masukkan data node referensi: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> databaru;
                sisipSebelum(data, databaru);
                break;
            case 10:
                clear();
                break;
            case 0:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 0);
}

// Fungsi utama
int main() {
    menu();
   return 0;
}