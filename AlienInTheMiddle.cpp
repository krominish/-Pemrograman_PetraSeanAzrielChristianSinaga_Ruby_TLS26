#include <iostream>
using namespace std;

int main() {
    const int MAKS_PANJANG = 1000;
    char pesan[MAKS_PANJANG];
    char hasil[MAKS_PANJANG];

    cout << "=== ALIEN-IN-THE-MIDDLE ===" << endl;
    cout << "Masukkan pesan asli (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    // menghitung panjang pesan secara manual (tanpa fungsi library strlen)
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }

    // huruf pertama tidak mengalami perubahan
    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        // nilai huruf berdasarkan posisi di alfabet, A=1, B=2, ..., Z=26
        int nilaiSekarang = pesan[i] - 'A' + 1;
        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

        // pergeseran huruf, jika melewati Z maka kembali ke A (perhitungan modulo 1..26)
        int nilaiBaru = (nilaiSekarang + nilaiSebelumnya - 1) % 26 + 1;

        hasil[i] = 'A' + (nilaiBaru - 1);
    }
    hasil[panjang] = '\0';

    cout << "\nPesan asli    : " << pesan << endl;
    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}