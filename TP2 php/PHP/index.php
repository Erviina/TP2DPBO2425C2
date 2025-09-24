<?php
require_once "TV.php";

session_start();
if (!isset($_SESSION['produkList'])) {
    $_SESSION['produkList'] = [
        new TV("T01", "Samsung Neo QLED", 15000000, "Samsung", "TV", 10, "55 inch", "4K", "QLED", "Samsung.jpg"),
        new TV("T02", "LG OLED CX", 18000000, "LG", "TV", 8, "65 inch", "4K", "OLED", "LG.jpg"),
        new TV("T03", "Sony Bravia", 20000000, "Sony", "TV", 6, "55 inch", "4K", "LED", "Sony.jpg"),
        new TV("T04", "Xiaomi Mi TV", 7000000, "Xiaomi", "TV", 12, "43 inch", "1080p", "LED", "xiomitv.jpg"),
        new TV("T05", "Polytron Cinemax", 5000000, "Polytron", "TV", 15, "32 inch", "720p", "LED", "Polytron.jpg"),
    ];
}
$produkList = &$_SESSION['produkList'];

// Handle input
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST["id"];
    $found = false;

    foreach ($produkList as $p) {
        if ($p->getId() == $id) {
            $tambah = intval($_POST["stok"]);
            $p->setStok($p->getStok() + $tambah);
            $found = true;
        }
    }

    if ($found == false) {
        $gambarFile = "";
        if (isset($_FILES["gambar"]) && $_FILES["gambar"]["error"] == 0) {
            $uploadDir = "uploads/";
            if (!is_dir($uploadDir)) mkdir($uploadDir);

            $fileName = basename($_FILES["gambar"]["name"]);
            $targetPath = $uploadDir . $fileName;

            if (move_uploaded_file($_FILES["gambar"]["tmp_name"], $targetPath)) {
                $gambarFile = $fileName;
            }
        }

        $produkList[] = new TV(
            $_POST["id"],
            $_POST["nama"],
            intval($_POST["harga"]),
            $_POST["merek"],
            $_POST["kategori"],
            intval($_POST["stok"]),
            $_POST["ukuran"],
            $_POST["resolusi"],
            $_POST["tipe_layar"],
            $gambarFile
        );
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Toko Elektronik - TV</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        h2 { text-align: center; }
        table { border-collapse: collapse; width: 100%; margin-top: 20px; }
        th, td { border: 1px solid black; padding: 8px; text-align: center; vertical-align: middle; }
        th { background-color: #f2f2f2; }
        img { max-width: 100px; height: auto; }
        fieldset { margin-top: 30px; padding: 15px; }
        legend { font-weight: bold; }
        .form-row { margin-bottom: 10px; }
        label { display: inline-block; width: 120px; text-align: right; margin-right: 10px; }
        input { padding: 5px; }
        button { padding: 5px 15px; margin-top: 10px; }
    </style>
</head>
<body>
<h2>📺 Toko Elektronik - Data TV</h2>

<table>
    <thead>
        <tr>
            <th>Gambar</th><th>ID</th><th>Nama</th><th>Harga</th>
            <th>Merek</th><th>Kategori</th><th>Stok</th>
            <th>Ukuran</th><th>Resolusi</th><th>Tipe Layar</th>
        </tr>
    </thead>
    <tbody>
    <?php foreach ($produkList as $p): ?>
        <tr>
            <td>
                <?php if ($p->getGambar() != "" && file_exists("uploads/" . $p->getGambar())): ?>
                    <img src="uploads/<?= $p->getGambar() ?>" alt="<?= $p->getNama() ?>">
                <?php else: ?>
                    <span style="color:gray;">No Image</span>
                <?php endif; ?>
            </td>
            <td><?= $p->getId() ?></td>
            <td><?= $p->getNama() ?></td>
            <td><?= number_format($p->getHarga(),0,',','.') ?></td>
            <td><?= $p->getMerek() ?></td>
            <td><?= $p->getKategori() ?></td>
            <td><?= $p->getStok() ?></td>
            <td><?= $p->getUkuran() ?></td>
            <td><?= $p->getResolusi() ?></td>
            <td><?= $p->getTipeLayar() ?></td>
        </tr>
    <?php endforeach; ?>
    </tbody>
</table>

<fieldset>
    <legend>➕ Tambah / Update Produk TV</legend>
    <form method="post" enctype="multipart/form-data">
        <div class="form-row">
            <label>ID:</label> <input type="text" name="id" required>
        </div>
        <div class="form-row">
            <label>Nama:</label> <input type="text" name="nama">
        </div>
        <div class="form-row">
            <label>Harga:</label> <input type="number" name="harga">
        </div>
        <div class="form-row">
            <label>Merek:</label> <input type="text" name="merek">
        </div>
        <div class="form-row">
            <label>Kategori:</label> <input type="text" name="kategori">
        </div>
        <div class="form-row">
            <label>Stok:</label> <input type="number" name="stok" required>
        </div>
        <div class="form-row">
            <label>Ukuran:</label> <input type="text" name="ukuran">
        </div>
        <div class="form-row">
            <label>Resolusi:</label> <input type="text" name="resolusi">
        </div>
        <div class="form-row">
            <label>Tipe Layar:</label> <input type="text" name="tipe_layar">
        </div>
        <div class="form-row">
            <label>Upload Gambar:</label> <input type="file" name="gambar">
        </div>
        <div class="form-row" style="text-align:center;">
            <button type="submit">💾 Simpan</button>
        </div>
    </form>
</fieldset>
</body>
</html>
