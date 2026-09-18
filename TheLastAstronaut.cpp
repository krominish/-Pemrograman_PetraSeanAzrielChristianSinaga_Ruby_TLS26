#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "=== THE LAST ASTRONAUT ===" << endl;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

   
    int* astronot = new int[N];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int ukuran = N; 
    int posisi = 0; 

    cout << "\nUrutan astronot yang dieliminasi:" << endl;

    while (ukuran > 1) {
        // hitungan ke-K jatuh pada index berikut (perhitungan melingkar)
        int indexEliminasi = (posisi + K - 1) % ukuran;
        int nomorTereliminasi = astronot[indexEliminasi];

        cout << "- Astronot " << nomorTereliminasi
             << " tereliminasi (K saat itu = " << K << ")" << endl;

        // menghapus astronot yang tereliminasi: geser semua elemen
        // setelahnya satu langkah ke kiri
        for (int i = indexEliminasi; i < ukuran - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        ukuran--;

        // posisi mulai hitung berikutnya adalah astronot yang kini
        // menempati index yang sama (karena array sudah bergeser)
        if (ukuran > 0) {
            posisi = indexEliminasi % ukuran;
        }

        // memperbarui nilai K sesuai aturan khusus
        if (nomorTereliminasi % 2 == 0) {
            K = K + 2; // nomor genap -> K bertambah 2
        } else {
            K = K - 1; // nomor ganjil -> K berkurang 1
        }
        if (K < 2) {
            K = 2; // K tidak boleh kurang dari 2
        }
    }

    cout << "\nAstronot terakhir yang bertahan: " << astronot[0] << endl;

    delete[] astronot;
    return 0;
}