<?php
require_once "Produk.php";

class Detail extends Produk {
    protected $merek;
    protected $kategori;
    protected $stok;

    public function __construct($id, $nama, $harga, $merek, $kategori, $stok) {
        parent::__construct($id, $nama, $harga);
        $this->merek = $merek;
        $this->kategori = $kategori;
        $this->stok = $stok;
    }

    public function setStok($stok) { $this->stok = $stok; }
    public function getMerek() { return $this->merek; }
    public function getKategori() { return $this->kategori; }
    public function getStok() { return $this->stok; }
}
