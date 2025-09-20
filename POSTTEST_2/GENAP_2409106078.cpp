#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struktur data untuk jadwal penerbangan
struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
};

// Global variables
Penerbangan* head = nullptr;

// Fungsi untuk mengecek apakah linked list kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk menampilkan header program
void tampilkanHeader() {
    cout << "\n";
    cout << "==============================================================\n";
    cout << "|                  SISTEM JADWAL PENERBANGAN                 |\n";
    cout << "|                  [ Richard - 2409106078 ]                  |\n";
    cout << "==============================================================\n";
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n==============================================================\n";
    cout << "|                         MENU UTAMA                         |\n";
    cout << "==============================================================\n";
    cout << "|  1. Tambah Jadwal Penerbangan                              |\n";
    cout << "|  2. Sisipkan Jadwal Penerbangan                            |\n";
    cout << "|  3. Hapus Jadwal Paling Awal                               |\n";
    cout << "|  4. Update Status Penerbangan                              |\n";
    cout << "|  5. Tampilkan Semua Jadwal                                 |\n";
    cout << "|  6. Cari Jadwal Penerbangan                                |\n";
    cout << "|  7. Hitung Total Jadwal                                    |\n";
    cout << "|  8. Hapus Semua Jadwal                                     |\n";
    cout << "|  0. Keluar                                                 |\n";
    cout << "==============================================================\n";
    cout << "Pilih menu (0-8): ";
}

int counter = 0;
// Fungsi untuk generate kode penerbangan berdasarkan NIM
string generateKodePenerbangan() {
    string nimTigaDigit = "078";
    
    string kode = "JT-" + nimTigaDigit;
    if (counter > 0) {
        kode += "-" + to_string(counter);
    }
    counter++;
    return kode;
}

// Fungsi untuk menghitung total jadwal
int hitungJadwal() {
    int count = 0;
    Penerbangan* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi Add Last - menambah jadwal di akhir
void addLast(string kode, string tujuan, string status) {
    Penerbangan* nodeBaru = new Penerbangan;
    nodeBaru->kodePenerbangan = kode;
    nodeBaru->tujuan = tujuan;
    nodeBaru->status = status;
    nodeBaru->next = nullptr;
    
    // jika linked list kosong
    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    
    // jika tidak, traversal ke node terakhir
    Penerbangan* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

// Fungsi Add Specific - menambah jadwal di posisi tertentu 
void addMiddle(string kode, string tujuan, string status, int posisi) {
    if (posisi <= 1) {
        // Add First
        Penerbangan* nodeBaru = new Penerbangan;
        nodeBaru->kodePenerbangan = kode;
        nodeBaru->tujuan = tujuan;
        nodeBaru->status = status;
        nodeBaru->next = head;
        head = nodeBaru;
        return;
    }
    
    Penerbangan* temp = head;
    int hitung = 1;
    
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    
    if (temp == nullptr) {
        cout << ">> Posisi tidak boleh melebihi panjang list <<" << endl;
        return;
    } else {
        Penerbangan* nodeBaru = new Penerbangan;
        nodeBaru->kodePenerbangan = kode;
        nodeBaru->tujuan = tujuan;
        nodeBaru->status = status;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

// Fungsi Delete First - menghapus jadwal paling awal 
void deleteFirst() {
    if (head == nullptr) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    cout << "\n=== HAPUS JADWAL PALING AWAL ===\n";
    cout << "Jadwal yang dihapus:\n";
    cout << "Kode: " << head->kodePenerbangan << endl;
    cout << "Tujuan: " << head->tujuan << endl;
    cout << "Status: " << head->status << endl;
    
    Penerbangan* temp = head;
    head = head->next;
    delete temp;
    cout << "\nJadwal paling awal berhasil dihapus!\n";
}

// Fungsi Display - menampilkan semua jadwal 
void display() {
    if (head == nullptr) {
        cout << ">> LinkedList kosong <<" << endl;
        return;
    }
    
    cout << "\n=== SEMUA JADWAL PENERBANGAN ===\n";
    cout << "==================================================================\n";
    cout << "| Kode Penerbangan|         Tujuan              |     Status     |\n";
    cout << "|=================|=============================|================|\n";
    
    Penerbangan* temp = head;
    while (temp != nullptr) {
        cout << "| " << left << setw(15) << temp->kodePenerbangan 
             << " | " << left << setw(27) << temp->tujuan 
             << " | " << left << setw(14) << temp->status << " |\n";
        temp = temp->next;
    }
    
    cout << "|=================|=============================|================|\n";
    cout << "Total Jadwal: " << hitungJadwal() << endl;
}

// Fungsi Edit Data - mengubah status penerbangan
void editData(string kode, string statusBaru) {
    if (head == nullptr) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    Penerbangan* temp = head;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "\nJadwal ditemukan:\n";
            cout << "Kode: " << temp->kodePenerbangan << endl;
            cout << "Tujuan: " << temp->tujuan << endl;
            cout << "Status Lama: " << temp->status << endl;
            
            temp->status = statusBaru;
            cout << "Status berhasil diubah menjadi: " << temp->status << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << ">> Kode penerbangan tidak ditemukan <<" << endl;
    }
}

// Fungsi Clear - menghapus semua jadwal
void clearList() {
    Penerbangan* temp;
    while (head != nullptr) {
        temp = head; // simpan pointer sementara
        head = head->next; // pindah ke node berikutnya
        delete temp; // hapus node lama
    }
    cout << "Linked list berhasil dikosongkan." << endl;
}

// Fungsi untuk mencari jadwal
void cariJadwal(string kode) {
    if (head == nullptr) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    Penerbangan* temp = head;
    int posisi = 1;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "\nJadwal ditemukan pada posisi " << posisi << ":\n";
            cout << "Kode: " << temp->kodePenerbangan << endl;
            cout << "Tujuan: " << temp->tujuan << endl;
            cout << "Status: " << temp->status << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
        posisi++;
    }
    
    if (!ditemukan) {
        cout << ">> Kode penerbangan tidak ditemukan <<" << endl;
    }
}

// Menu 1: Tambah Jadwal Penerbangan
void tambahJadwal() {
    cout << "\n=== TAMBAH JADWAL PENERBANGAN ===\n";
    
    string kode = generateKodePenerbangan();
    cout << "Kode Penerbangan : " << kode << endl;
    
    string tujuan, status;
    cout << "Masukkan Tujuan: ";
    cin.ignore();
    getline(cin, tujuan);
    
    cout << "Masukkan Status (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, status);
    
    addLast(kode, tujuan, status);
    cout << "\nJadwal berhasil ditambahkan!\n";
}

// Menu 2: Sisipkan Jadwal Penerbangan
void sisipkanJadwal() {
    if (isEmpty()) {
        cout << "\nDaftar jadwal kosong. Tambahkan jadwal terlebih dahulu.\n";
        return;
    }
    
    // Hitung posisi sisip berdasarkan digit terakhir NIM
    string nimTigaDigit = "078";
    int digitTerakhir = stoi(nimTigaDigit.substr(2, 1)); // Ambil digit terakhir
    int posisiSisip = (digitTerakhir == 0) ? 2 : digitTerakhir + 1;
    
    cout << "\n=== SISIPKAN JADWAL PENERBANGAN ===\n";
    cout << "Posisi sisip otomatis: " << posisiSisip << endl;
    
    // Cek apakah posisi sisip valid
    int totalJadwal = hitungJadwal();
    if (posisiSisip > totalJadwal + 1) {
        cout << "Posisi sisip (" << posisiSisip << ") melebihi jumlah jadwal + 1 (" << totalJadwal + 1 << ")\n";
        cout << "Jadwal akan ditambahkan di akhir.\n";
        tambahJadwal();
        return;
    }
    
    string kode = generateKodePenerbangan();
    cout << "Kode Penerbangan : " << kode << endl;
    
    string tujuan, status;
    cout << "Masukkan Tujuan: ";
    cin.ignore();
    getline(cin, tujuan);
    
    cout << "Masukkan Status (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, status);
    
    addMiddle(kode, tujuan, status, posisiSisip);
    cout << "\nJadwal berhasil disisipkan di posisi " << posisiSisip << "!\n";
}

// Menu 3: Hapus Jadwal Paling Awal
void hapusJadwalPalingAwal() {
    deleteFirst();
}

// Menu 4: Update Status Penerbangan
void updateStatusPenerbangan() {
    if (isEmpty()) {
        cout << "\nTidak ada jadwal untuk diupdate.\n";
        return;
    }
    
    string kode, statusBaru;
    cout << "\n=== UPDATE STATUS PENERBANGAN ===\n";
    cout << "Masukkan Kode Penerbangan: ";
    cin.ignore();
    getline(cin, kode);
    
    cout << "Masukkan Status Baru: ";
    getline(cin, statusBaru);
    
    editData(kode, statusBaru);
    cout << "\nUpdate status selesai!\n";
}

// Menu 5: Tampilkan Semua Jadwal
void tampilkanSemuaJadwal() {
    display();
}

// Menu 6: Cari Jadwal Penerbangan
void cariJadwalPenerbangan() {
    if (isEmpty()) {
        cout << "\nTidak ada jadwal untuk dicari.\n";
        return;
    }
    
    string kode;
    cout << "\n=== CARI JADWAL PENERBANGAN ===\n";
    cout << "Masukkan Kode Penerbangan: ";
    cin.ignore();
    getline(cin, kode);
    
    cariJadwal(kode);
}

// Menu 7: Hitung Total Jadwal
void hitungTotalJadwal() {
    string nimTigaDigit = "078";
    int digitTerakhir = stoi(nimTigaDigit.substr(2, 1));
    int posisiSisip = (digitTerakhir == 0) ? 2 : digitTerakhir + 1;
    
    cout << "\n=== INFORMASI SISTEM ===\n";
    cout << "Total Jadwal Penerbangan: " << hitungJadwal() << endl;
    cout << "Posisi Sisip Otomatis: " << posisiSisip << endl;
    cout << "Format Kode: JT-" << nimTigaDigit << endl;
    cout << "Status Linked List: " << (isEmpty() ? "Kosong" : "Ada Data") << endl;
}

// Menu 8: Hapus Semua Jadwal
void hapusSemuaJadwal() {
    if (isEmpty()) {
        cout << "\nTidak ada jadwal untuk dihapus.\n";
        return;
    }
    
    char konfirmasi;
    cout << "\n=== HAPUS SEMUA JADWAL ===\n";
    cout << "Yakin ingin menghapus semua jadwal? (y/n): ";
    cin >> konfirmasi;
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        clearList();
        cout << "\nSemua jadwal berhasil dihapus!\n";
    } else {
        cout << "\nOperasi dibatalkan.\n";
    }
}

// Main program
int main() {
    int pilihan;
    
    do {
        tampilkanHeader();
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahJadwal();
                break;
            case 2:
                sisipkanJadwal();
                break;
            case 3:
                hapusJadwalPalingAwal();
                break;
            case 4:
                updateStatusPenerbangan();
                break;
            case 5:
                tampilkanSemuaJadwal();
                break;
            case 6:
                cariJadwalPenerbangan();
                break;
            case 7:
                hitungTotalJadwal();
                break;
            case 8:
                hapusSemuaJadwal();
                break;
            case 0:
                cout << "\n=== TERIMA KASIH ===\n";
                cout << "Program selesai. Sampai jumpa!\n";
                // Bersihkan memory sebelum keluar
                clearList();
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
        
        if (pilihan != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 0);
    
    return 0;
}