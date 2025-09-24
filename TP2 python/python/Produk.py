class Produk:       # kelas produk
    # konstruktor untuk menginisialisasi atribut dasar produk
    def __init__(self, id="", nama="", harga=0):
        self.id = id            # menyimpan ID produk
        self.nama = nama        # menyimpan nama produk
        self.harga = harga      # menyimpan harga produk

    #getter untuk mengambil nilai
    def get_id(self): return self.id
    def get_nama(self): return self.nama
    def get_harga(self): return self.harga
