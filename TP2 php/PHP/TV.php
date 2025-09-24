<?php
require_once "Detail.php";

class TV extends Detail {
    private $ukuran;
    private $resolusi;
    private $tipeLayar;
    private $gambar; // nama file gambar

    public function __construct($id, $nama, $harga, $merek, $kategori, $stok, $ukuran, $resolusi, $tipeLayar, $gambar) {
        parent::__construct($id, $nama, $harga, $merek, $kategori, $stok);
        $this->ukuran = $ukuran;
        $this->resolusi = $resolusi;
        $this->tipeLayar = $tipeLayar;
        $this->gambar = $gambar;
    }

    public function getUkuran() { return $this->ukuran; }
    public function getResolusi() { return $this->resolusi; }
    public function getTipeLayar() { return $this->tipeLayar; }
    public function getGambar() { return $this->gambar; }
}
