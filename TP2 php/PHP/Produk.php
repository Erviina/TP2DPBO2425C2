<?php
class Produk {
    protected $id;
    protected $nama;
    protected $harga;

    public function __construct($id, $nama, $harga) {
        $this->id = $id;
        $this->nama = $nama;
        $this->harga = $harga;
    }

    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getHarga() { return $this->harga; }
}
