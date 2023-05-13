<?php include("koneksi.php");

if (isset($_GET['id'])) {
    // SELECT MAX( `id` ) FROM `mahasiswa` ;
    // ALTER TABLE `mahasiswa` AUTO_INCREMENT = number;
    $id = $_GET['id'];

    $sql = "DELETE from mahasiswa where id=$id";

    $query = mysqli_query($koneksi, $sql);

    if ($query) {
        header('Location: index.php');
    } else {
        die("Gagal menghapus...");
    }
} else {
    die("akses dilarang");
}
