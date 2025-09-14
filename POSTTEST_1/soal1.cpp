#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int data[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < 7; i++) cout << data[i] << " ";
    cout << endl;

    balikArray(data, 7);

    cout << "Array setelah dibalik: ";
    for (int i = 0; i < 7; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}
