<?php include("koneksi.php"); ?>

<?php
if (isset($_POST['tambah'])) {

    $nama = $_POST['nama'];
    $alamat = $_POST['alamat'];
    $jk = $_POST['jenis_kelamin'];
    $agama = $_POST['agama'];
    // $sekolah = $_POST['sekolah_asal'];
    $nim = $_POST['nim'];

    $sql = "INSERT INTO mahasiswa (nama, alamat, jenis_kelamin, agama, nim) VALUE ('$nama', '$alamat', '$jk', '$agama', '$nim')";
    $query = mysqli_query($koneksi, $sql);

    if ($query) {
        header('Location: index.php?status=sukses');
    } else {
        header('Location: index.php?status=gagal');
    }
} else {
    die("Akses dilarang...");
}
