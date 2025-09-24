public class TV extends Detail {        // inheritance dengan kelas detail
    // tambahan atribut khusus kelas tv
    private String ukuran;
    private String resolusi;
    private String tipeLayar;

    // constructor nilai awal
    public TV() {
        super();            // panggil constructor Detail
        this.ukuran = "";
        this.resolusi = "";
        this.tipeLayar = "";
    }

    // constructor isi semua data produk
    public TV(String id, String nama, int harga, String merek, String kategori, int stok,
              String ukuran, String resolusi, String tipeLayar) {
        super(id, nama, harga, merek, kategori, stok);          // panggil constructor Detail
        this.ukuran = ukuran;
        this.resolusi = resolusi;
        this.tipeLayar = tipeLayar;
    }

    // getter
    public String getUkuran() { return ukuran; }
    public String getResolusi() { return resolusi; }
    public String getTipeLayar() { return tipeLayar; }
}
