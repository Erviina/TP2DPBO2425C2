from TV import TV

def max_len(data, kolom):
    mx = 0      # Variabel untuk menyimpan panjang maksimal
    for t in data:
        # Mengecek kolom yang diminta dan ambil nilainya
        if kolom == 0: val = t.get_id()
        elif kolom == 1: val = t.get_nama()
        elif kolom == 2: val = str(t.get_harga())
        elif kolom == 3: val = t.get_merek()
        elif kolom == 4: val = t.get_kategori()
        elif kolom == 5: val = str(t.get_stok())
        elif kolom == 6: val = t.get_ukuran()
        elif kolom == 7: val = t.get_resolusi()
        elif kolom == 8: val = t.get_tipe_layar()
        # Cek apakah panjang string lebih besar dari sebelumnya
        if len(val) > mx:
            mx = len(val)
    return mx

def main():
    # daftar awal
    daftar_tv = [
        TV("T01","Samsung Neo QLED",15000000,"Samsung","TV",10,"55 inch","4K","QLED"),
        TV("T02","LG OLED CX",18000000,"LG","TV",8,"65 inch","4K","OLED"),
        TV("T03","Sony Bravia",20000000,"Sony","TV",6,"55 inch","4K","LED"),
        TV("T04","Xiaomi Mi TV",7000000,"Xiaomi","TV",12,"43 inch","1080p","LED"),
        TV("T05","Polytron Cinemax",5000000,"Polytron","TV",15,"32 inch","720p","LED")
    ]

    # menanyakan apakah user ingin menambah produk baru
    pilihan = input("Apakah ingin menambah produk baru? (y/n): ")

    # selama user masih memilih 'y', lakukan perulangan
    while pilihan.lower() == 'y':
        id = input("Masukkan ID: ")     # input ID produk baru
        found = False       # untuk cek apakah ID sudah ada

        # mengecek apakah ID sudah ada 
        for tv in daftar_tv:
            if tv.get_id() == id:
                tambahan = int(input(f"Produk dengan ID {id} sudah ada.\nMasukkan tambahan stok: "))
                # jika ID sudah ada, tambahkan stok
                tv.set_stok(tv.get_stok() + tambahan)
                print(f"Stok berhasil diperbarui. Stok sekarang: {tv.get_stok()}")
                found = True

        # jika ID belum ada, maka tambahkan produk baru
        if not found:
            nama = input("Masukkan Nama: ")
            harga = int(input("Masukkan Harga: "))
            merek = input("Masukkan Merek: ")
            kategori = input("Masukkan Kategori: ")
            stok = int(input("Masukkan Stok: "))
            ukuran = input("Masukkan Ukuran: ")
            resolusi = input("Masukkan Resolusi: ")
            tipe_layar = input("Masukkan Tipe Layar: ")

            # tambahkan produk baru ke daftar
            daftar_tv.append(TV(id, nama, harga, merek, kategori, stok, ukuran, resolusi, tipe_layar))
            print("Produk baru berhasil ditambahkan.")

        # tanya lagi apakah ingin tambah produk lagi
        pilihan = input("Tambah produk lagi? (y/n): ")

    # Print judul tabel
    header = ["ID","Nama","Harga","Merek","Kategori","Stok","Ukuran","Resolusi","Tipe Layar"]
    # hitung lebar kolom secara dinamis
    width = []
    for i in range(9):
        width.append(max(len(header[i]), max_len(daftar_tv,i)))

    # header
    print("".join([f"+-{'-'*w}-" for w in width]) + "+")
    print("".join([f"| {header[i]:<{width[i]}} " for i in range(9)]) + "|")
    print("".join([f"+-{'-'*w}-" for w in width]) + "+")

    # data
    for t in daftar_tv:
        row = [
            t.get_id(), t.get_nama(), str(t.get_harga()),
            t.get_merek(), t.get_kategori(), str(t.get_stok()),
            t.get_ukuran(), t.get_resolusi(), t.get_tipe_layar()
        ]
        print("".join([f"| {row[i]:<{width[i]}} " for i in range(9)]) + "|")

    print("".join([f"+-{'-'*w}-" for w in width]) + "+")

if __name__ == "__main__":
    main()
