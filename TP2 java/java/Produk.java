public class Produk {
    // atribut produk
    protected String id;
    protected String nama;
    protected int harga;

    //constructor nilai awal
    public Produk() {
        this.id = "";
        this.nama = "";
        this.harga = 0;
    }
    
    //constructor pengisian data
    public Produk(String id, String nama, int harga) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
    }

    // getter untuk ambil nilai
    public String getId() { return id; }
    public String getNama() { return nama; }
    public int getHarga() { return harga; }
}
