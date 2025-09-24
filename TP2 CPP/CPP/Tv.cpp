#ifndef TV_H
#define TV_H
#include "Detail.cpp"           // inherit dari detail


//class tv turunan dari detail
class TV : public Detail {
private:
    string ukuran;          // atribut ukuran tv
    string resolusi;        // atribut resolusi tv
    string tipeLayar;       // atribut tipe layar tv
public:
    //constructor default
    TV() : Detail () {
        ukuran = "";        //ukuran kosong
        resolusi = "";      //resolusi kosong
        tipeLayar = "";     // tipe layar kosong
    }

    //constructor untuk isi 
    TV(string id, string nama, int harga, string merek, string kategori, int stok,
       string ukuran, string resolusi, string tipeLayar)
        : Detail(id, nama, harga, merek, kategori, stok) {
        this->ukuran = ukuran;          //isi ukuran
        this->resolusi = resolusi;      //isi resolusi
        this->tipeLayar = tipeLayar;     //isi tipe layar
    }

    // getter
    string getUkuran() { return ukuran; }               // getter ukuran
    string getResolusi() { return resolusi; }           // getter resolusi
    string getTipeLayar() { return tipeLayar; }         // getter tipe layar
};

#endif
