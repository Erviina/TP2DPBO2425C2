Saya Ervina Kusnanda dengan NIM 2409082 mengerjakan Tugas Praktikum 2 dalam mata kuliah Desain Pemogramana Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

Untuk membuat lebih terstruktuk di buatlah tiga kelas. Kelas Produk jadi kelas dasar untuk atribut umum seperti id, nama, dan harga. Lalu ada kelas Detail yang menambahkan atribut merek, kategori, dan stok supaya lebih spesifik. Terakhir ada kelas TV yang mewarisi semuanya dan menambah atribut khusus seperti ukuran, resolusi, tipe layar, dan gambar. Menurut saya dengan desain ini, program jadi rapi, mudah dibaca, dan gampang dikembangkan kalau mau nambah produk lain.

## Diagram
![Diagram](https://github.com/Erviina/TP2DPBO2425C2/blob/main/diagram%20TP2.png?raw=true)



- kelas Produk
    Atribut: id, nama, harga
    Method: constructor untuk ngisi data, getter untuk ambil data

- Detail (extends Produk)
    Atribut tambahan: merek, kategori, stok
    Method: constructor yang manggil constructor Produk juga    

- TV (extends Detail)
    Atribut tambahan: ukuran, resolusi, tipe layar, dan gambar(khusus php)
    Method: constructor yang manggil constructor Detail, getter untuk ambil semua data

## Alur programnya :

 dimulai dengan pembuatan beberapa data awal berupa objek TV yang sudah diisi dengan nilai default. Setelah itu, pengguna juga bisa menambahkan data baru secara manual. Data yang diisi pengguna kemudian diproses, ada pengecekan ID terlebih dahulu apakah ID dari input user itu sudah ada dalam data atau belum. Jika ID sudah ada maka program hanya akan menambahkan sdata stok saja, jika ID belum ada dalam dataa maka dibuat menjadi objek TV baru yang ditambahkan ke dalam daftar produk. Semua data yang ada, baik yang bawaan maupun hasil input pengguna, kemudian ditampilkan dalam bentuk tabel dinamis. Tabel ini menampilkan setiap atribut sebagai kolom, sementara baris tabel mewakili setiap produk TV. Untuk bagian gambar, program akan menampilkan foto produk berdasarkan path yang sudah disimpan.

 Secara sederhana, desain ini menggambarkan bagaimana sebuah toko elektronik bisa dikelola secara digital. Produk menjadi representasi umum barang, Detail menambahkan informasi ketersediaan, dan TV menambahkan visualisasi berupa gambar.


 ## Dokumentasi

 **Tampilan output CPP**
 ![Tampilan CPP](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20CPP/Dokumentasi/tampilkan%20cpp.png?raw=true)

 **Tambah Produk CPP**
 ![Tambah CPP](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20CPP/Dokumentasi/tambah%20cpp.png?raw=true)

 **Tambah produk dengan ID yg sudah ada**
  ![Coba Tambah CPP](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20CPP/Dokumentasi/coba%20tambah%20cpp.png?raw=true)

   **Tampilan output python**
 ![Tampilan python](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20python/dokumentasi/tampilkan%20python.png?raw=true)

 **Tambah Produk python**
 ![Tambah python](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20python/dokumentasi/tambah%20python.png?raw=true)

 **Tambah produk dengan ID yg sudah ada python**
  ![Coba Tambah python](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20python/dokumentasi/coba%20tambah%20python.png?raw=true)

**Tampilan output java**
 ![Tampilan java](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20java/Dokumentasi/tampilkan%20java.png?raw=true)

 **Tambah Produk java**
 ![Tambah java](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20java/Dokumentasi/tambah%20java.png?raw=true)

 **Tambah produk dengan ID yg sudah ada java**
  ![Coba Tambah java](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20java/Dokumentasi/coba%20tambah%20java.png?raw=true)

  **Tampilan output PHP**
 ![Tampilan PHP](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20php/Dokumentasi/tampilan%20php.png?raw=true)

 **Tambah Produk PHP**
 ![Tambah PHP](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20php/Dokumentasi/tambah%20php.png?raw=true)

 **Tambah produk berhasil PHP**
  ![Coba Tambah PHP](https://github.com/Erviina/TP2DPBO2425C2/blob/main/TP2%20php/Dokumentasi/berhasil%20tambah%20php.png?raw=true)

