#ifndef PRODUK_H
#define PRODUK_H
#include <iostream>
#include <string>
using namespace std;

//class produk sebagai parent
class Produk {
protected:
    string id;      // atribut ID Produk
    string nama;    // atribut nama Produk
    int harga;      // atribut harga Produk
public:
    // constuctor default
    Produk() {
        id = "";        // ID di isi string kosong
        nama = "";      // nama diisi string kosong
        harga = 0;      // isi di 0
    }

    // constuctor untuk mengisi atribut
    Produk(string id, string nama, int harga) {
        this->id = id;          // isi atribut ID
        this->nama = nama;      // isi atribut nama
        this->harga = harga;    // isi atribut harga
    }

    string getId() { return id; }           // getter untuk mengambil ID
    string getNama() { return nama; }       // getter untuk mengambil nama
    int getHarga() { return harga; }        // getter untuk mengambil harga
};

#endif
