from Detail import Detail

class TV(Detail):
     # konstruktor dengan atribut tambahan khusus TV
    def __init__(self, id="", nama="", harga=0, merek="", kategori="", stok=0,
                 ukuran="", resolusi="", tipe_layar=""):
        super().__init__(id, nama, harga, merek, kategori, stok)        # Memanggil konstruktor detail
        self.ukuran = ukuran            # Menyimpan ukuran TV
        self.resolusi = resolusi        # Menyimpan resolusi TV
        self.tipe_layar = tipe_layar    # Menyimpan tipe layar TV

    # getter
    def get_ukuran(self): return self.ukuran
    def get_resolusi(self): return self.resolusi
    def get_tipe_layar(self): return self.tipe_layar
