<?php

include("koneksi.php");
if (isset($_POST['simpan'])) {

    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $alamat = $_POST['alamat'];
    $jk = $_POST['jenis_kelamin'];
    $agama = $_POST['agama'];
    $nim = $_POST['nim'];

    $sql = "UPDATE mahasiswa SET nama='$nama', alamat='$alamat', jenis_kelamin='$jk', agama='$agama', nim='$nim' WHERE id=$id";
    $query = mysqli_query($koneksi, $sql);

    if ($query) {
        // kalau berhasil alihkan ke halaman list-siswa.php
        header('Location: index.php');
    } else {

        die("Gagal menyimpan perubahan...");
    }
}
