public class Detail extends Produk {            // inheritance dari kelas produk
    // atribut tambahan untuk detail
    protected String merek;
    protected String kategori;
    protected int stok;

    //constructor nilai awal
    public Detail() {
        super();            // panggil constructor Produk()
        this.merek = "";
        this.kategori = "";
        this.stok = 0;
    }

    //constructor isi data
    public Detail(String id, String nama, int harga, String merek, String kategori, int stok) {
        super(id, nama, harga);
        this.merek = merek;
        this.kategori = kategori;
        this.stok = stok;
    }

    public void setStok(int stok) { this.stok = stok; }         // setter untuk mengubah stok
    public String getMerek() { return merek; }                  // getter untuk ambil merek
    public String getKategori() { return kategori; }            // getter untuk ambil kategori
    public int getStok() { return stok; }                       // getter untuk ambil stok
}
