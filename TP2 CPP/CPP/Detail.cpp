#ifndef ELEKTRONIK_H
#define ELEKTRONIK_H
#include "Produk.cpp"           // inheritance dari class produk


// class detail turunan dari produk
class Detail : public Produk {
protected:
    string merek;           // atribut merek produk
    string kategori;        // atribut kategori produk
    int stok;               // atribut stok produk
public:
    // constructor kosong
    Detail() : Produk() {
        merek = "";         // merek kosong
        kategori = "";      // kategori kosong
        stok = 0;           // stok kosong
    }

    //constructor untuk mengisi
    Detail(string id, string nama, int harga, string merek, string kategori, int stok)
        : Produk(id, nama, harga) {
        this->merek = merek;            // isi merek
        this->kategori = kategori;      // isi kategori
        this->stok = stok;              // isi stok
    }

    // setter stok untuk update stok
    void setStok(int stok) {
        this->stok = stok;
    }

    string getMerek() { return merek; }             // getter untuk ambil data merek
    string getKategori() { return kategori; }       // getter untuk ambil data kategori
    int getStok() { return stok; }                  // getter untuk ambil data stok
};

#endif
