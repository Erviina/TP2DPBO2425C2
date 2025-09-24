#include <iostream>
#include <vector>
#include <iomanip>
#include "Tv.cpp"           // import class tv
using namespace std;

// Fungsi untuk menghitung lebar kolom maksimum dari data
int maxLen(vector<TV>& data, int kolom) {
    int mx = 0;                // variabel untuk simpan panjang maksimum
    for (auto &t : data) {     // loop semua data tv
        string val;
        switch(kolom) {         // pilih kolom yg di cek
            case 0: val = t.getId(); break;                 // kolom ID
            case 1: val = t.getNama(); break;               // kolom nama
            case 2: val = to_string(t.getHarga()); break;   // kolom harga
            case 3: val = t.getMerek(); break;              // kolom merek
            case 4: val = t.getKategori(); break;           // kolom kategori
            case 5: val = to_string(t.getStok()); break;    // kolom stok
            case 6: val = t.getUkuran(); break;             // kolom ukuran
            case 7: val = t.getResolusi(); break;           // kolom resolusi
            case 8: val = t.getTipeLayar(); break;          // kolom tipe layar
        }
        if ((int)val.size() > mx) mx = val.size();          // ambil yg terpanjang
    }
    return mx;
}

int main() {
    vector<TV> daftarTV;        // vector untuk simpan daftar tv

    // 5 objek awal
    daftarTV.push_back(TV("T01", "Samsung Neo QLED", 15000000, "Samsung", "TV", 10, "55 inch", "4K", "QLED"));
    daftarTV.push_back(TV("T02", "LG OLED CX", 18000000, "LG", "TV", 8, "65 inch", "4K", "OLED"));
    daftarTV.push_back(TV("T03", "Sony Bravia", 20000000, "Sony", "TV", 6, "55 inch", "4K", "LED"));
    daftarTV.push_back(TV("T04", "Xiaomi Mi TV", 7000000, "Xiaomi", "TV", 12, "43 inch", "1080p", "LED"));
    daftarTV.push_back(TV("T05", "Polytron Cinemax", 5000000, "Polytron", "TV", 15, "32 inch", "720p", "LED"));

    // Input manual dari user
    char pilihan;
    cout << "Apakah ingin menambah produk baru? (y/n): ";
    cin >> pilihan;
    cin.ignore();       // buang karakter newline
    
    // Selama pilihan user 'y' atau 'Y', ulangi input
    while (pilihan == 'y' || pilihan == 'Y') {
        string id;
        cout << "Masukkan ID: ";
        getline(cin, id);       // baca ID produk

        bool found = false;     // cek ID sudah ada atau belum
        for (int i = 0; i < daftarTV.size(); i++) {
            if (daftarTV[i].getId() == id) {            // jika ID sama
                int tambahan;
                cout << "Produk dengan ID " << id << " sudah ada.\n";
                cout << "Masukkan tambahan stok: ";
                cin >> tambahan;
                cin.ignore();

                // update stok produk lama
                daftarTV[i].setStok(daftarTV[i].getStok() + tambahan);
                cout << "Stok berhasil diperbarui. Stok sekarang: "
                     << daftarTV[i].getStok() << endl;

                found = true;       // tandai produk ditemukan
            }
        }

        // jika produk belum ada tandai sebagai produk baru
        if (!found) {
            string nama, merek, kategori, ukuran, resolusi, tipeLayar;
            int harga, stok;

            
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan Harga: ";
            cin >> harga;
            cout << "Masukkan Merek: ";
            cin >> merek;
            cout << "Masukkan Kategori: ";
            cin >> kategori;
            cout << "Masukkan Stok: ";
            cin >> stok;
            cout << "Masukkan Ukuran: ";
            cin.ignore();
            getline(cin, ukuran);
            cout << "Masukkan Resolusi: ";
            getline(cin, resolusi);
            cout << "Masukkan Tipe Layar: ";
            getline(cin, tipeLayar);

            // tambahkan produk baru ke vector
            daftarTV.push_back(TV(id, nama, harga, merek, kategori, stok, ukuran, resolusi, tipeLayar));
            cout << "Produk baru berhasil ditambahkan." << endl;

        }

        cout << "Tambah produk lagi? (y/n): ";
        cin >> pilihan;
        cin.ignore();
    }

    // Hitung panjang tiap kolom tabel
    vector<int> width(9);
    vector<string> header = {"ID","Nama","Harga","Merek","Kategori","Stok","Ukuran","Resolusi","Tipe Layar"};
    for (int i=0; i<9; i++) {
        width[i] = header[i].size();        // minimal pakai panjang header
        int w = maxLen(daftarTV,i);         // cari data terpanjang
        if (w > width[i]) width[i] = w;
    }

    // Print garis atas tabel
    for (int i=0; i<9; i++) cout << "+-" << string(width[i], '-') << "-";
    cout << "+" << endl;
    // print header tabel
    for (int i=0; i<9; i++) cout << "| " << left << setw(width[i]) << header[i] << " ";
    cout << "|" << endl;
    // print garis pembatas header
    for (int i=0; i<9; i++) cout << "+-" << string(width[i], '-') << "-";
    cout << "+" << endl;

    // Print data
    for (auto &t : daftarTV) {
        cout << "| " << left << setw(width[0]) << t.getId() << " ";
        cout << "| " << left << setw(width[1]) << t.getNama() << " ";
        cout << "| " << left << setw(width[2]) << t.getHarga() << " ";
        cout << "| " << left << setw(width[3]) << t.getMerek() << " ";
        cout << "| " << left << setw(width[4]) << t.getKategori() << " ";
        cout << "| " << left << setw(width[5]) << t.getStok() << " ";
        cout << "| " << left << setw(width[6]) << t.getUkuran() << " ";
        cout << "| " << left << setw(width[7]) << t.getResolusi() << " ";
        cout << "| " << left << setw(width[8]) << t.getTipeLayar() << " ";
        cout << "|" << endl;
    }

    // print garis bawah tabel
    for (int i=0; i<9; i++) cout << "+-" << string(width[i], '-') << "-";
    cout << "+" << endl;

    return 0;
}
