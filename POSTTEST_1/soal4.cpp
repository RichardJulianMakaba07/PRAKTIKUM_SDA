#include <iostream>
using namespace std;

// fungsi untuk menukar dua integer menggunakan reference
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: "; cin >> x;
    cout << "Masukkan nilai y: "; cin >> y;

    cout << "Sebelum ditukar: x = " << x << ", y = " << y << endl;
    tukar(x, y);
    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;

    return 0;
}
