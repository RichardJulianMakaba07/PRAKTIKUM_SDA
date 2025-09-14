#include <iostream>
#include <algorithm> // untuk sort
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

bool pembanding(Mahasiswa a, Mahasiswa b) {
    return a.ipk < b.ipk; // ascending
}

int main() {
    Mahasiswa mahasiswa[4];

    for(int i = 0; i < 4; i++) {
        cout << "Mahasiswa " << i+1 << ":" << endl;
        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
        cin.ignore(); // Bersihkan buffer
    }

    // urutkan berdasarkan ipk
    sort(mahasiswa, mahasiswa+4, pembanding);

    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK (ascending):" << endl;
    for (int i = 0; i < 4; i++) {
        cout << mahasiswa[i].nama << " | " << mahasiswa[i].nim << " | " << mahasiswa[i].ipk << endl;
    }

    return 0;
}
