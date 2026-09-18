#include <iostream>
using namespace std;

// Fungsi user-defined: mencari indeks astronot yang masih hidup
// mulai dari indeks 'start' (bergerak maju melingkar)
int nextAlive(bool alive[], int N, int start) {
    int idx = start % N;
    while (!alive[idx]) {
        idx = (idx + 1) % N;
    }
    return idx;
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    bool* alive = new bool[N];
    for (int i = 0; i < N; i++) {
        alive[i] = true; // indeks 0 = astronot nomor 1, dst.
    }

    int* order = new int[N];
    int orderCount = 0;

    int countAlive = N;
    int cur = 0; // hitungan dimulai dari astronot nomor 1

    while (countAlive > 1) {
        int idx = cur;

        // Bergerak sebanyak (K-1) langkah dari titik awal
        // karena titik awal sendiri dihitung sebagai hitungan ke-1
        for (int step = 1; step < K; step++) {
            idx = nextAlive(alive, N, idx + 1);
        }

        int eliminatedNumber = idx + 1;
        order[orderCount] = eliminatedNumber;
        orderCount++;

        alive[idx] = false;
        countAlive--;

        // Titik awal hitungan berikutnya: astronot tepat setelah yang dieliminasi
        if (countAlive > 0) {
            cur = nextAlive(alive, N, idx + 1);
        }

        // Update nilai K sesuai aturan khusus
        if (eliminatedNumber % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }
    }

    // Cari astronot yang tersisa
    int survivor = -1;
    for (int i = 0; i < N; i++) {
        if (alive[i]) {
            survivor = i + 1;
            break;
        }
    }

    cout << "\nUrutan astronot yang dieliminasi:\n";
    for (int i = 0; i < orderCount; i++) {
        cout << order[i];
        if (i != orderCount - 1) {
            cout << " -> ";
        }
    }
    cout << "\n\nAstronot terakhir yang bertahan: " << survivor << endl;

    delete[] alive;
    delete[] order;
    return 0;
}
