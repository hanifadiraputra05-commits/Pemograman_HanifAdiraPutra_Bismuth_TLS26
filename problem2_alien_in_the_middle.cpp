#include <iostream>
using namespace std;

int main() {
    const int MAX = 1000;
    char message[MAX];

    cout << "Masukkan pesan (huruf kapital tanpa spasi): ";
    cin.getline(message, MAX);

    // Menghitung panjang pesan secara manual (tanpa strlen)
    int len = 0;
    while (message[len] != '\0') {
        len++;
    }

    int origVal[MAX];
    char result[MAX];

    // Nilai asli tiap huruf: A=1, B=2, ..., Z=26
    for (int i = 0; i < len; i++) {
        origVal[i] = message[i] - 'A' + 1;
    }

    // Proses penyandian
    for (int i = 0; i < len; i++) {
        int newVal;
        if (i == 0) {
            // Huruf pertama tidak berubah
            newVal = origVal[i];
        } else {
            newVal = origVal[i] + origVal[i - 1];
            if (newVal > 26) {
                newVal = newVal - 26; // putar kembali ke A jika melewati Z
            }
        }
        result[i] = 'A' + (newVal - 1);
    }
    result[len] = '\0';

    cout << "Pesan asli    : " << message << endl;
    cout << "Pesan tersandi: " << result << endl;

    return 0;
}
