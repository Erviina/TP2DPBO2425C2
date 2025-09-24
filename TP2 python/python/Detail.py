from Produk import Produk       #inheritance dari kelas produk

class Detail(Produk):
    # konstruktor dengan tambahan atribut baru
    def __init__(self, id="", nama="", harga=0, merek="", kategori="", stok=0):
        super().__init__(id, nama, harga)       # memanggil konstruktor produk
        self.merek = merek              # menyimpan merek produk
        self.kategori = kategori        # menyimpan kategori produk
        self.stok = stok                # menyimpan stok produk

    def set_stok(self, stok): self.stok = stok       #method untuk mengubah nilai stok produk

     # getter untuk mengambil nilai
    def get_merek(self): return self.merek
    def get_kategori(self): return self.kategori
    def get_stok(self): return self.stok
