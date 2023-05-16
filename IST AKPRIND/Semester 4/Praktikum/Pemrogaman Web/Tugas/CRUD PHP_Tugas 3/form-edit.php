<?php

include("koneksi.php");
if (!isset($_GET['id'])) {
    header('Location: list-siswa.php');
}
$id = $_GET['id'];

$sql = "SELECT * FROM mahasiswa WHERE id=$id";
$query = mysqli_query($koneksi, $sql);
$mahasiswa = mysqli_fetch_assoc($query);

if (mysqli_num_rows($query) < 1) {
    die("data tidak ditemukan...");
}

?>

<!DOCTYPE html>
<html>

<head>
    <title>Edit Mahasiswa</title>
</head>

<body>
    <header>
        <h3>Edit Mahasiswa</h3>
    </header>

    <form action="proses-edit.php" method="POST">

        <fieldset>

            <input type="hidden" name="id" value="<?php echo $mahasiswa['id'] ?>" />

            <p>
                <label for="nama">Nama: </label>
                <input type="text" name="nama" placeholder="nama lengkap" value="<?php echo $mahasiswa['nama'] ?>" />
            </p>
            <p>
                <label for="nim">NIM: </label>
                <input type="text" name="nim" placeholder="isikan nim" />
            </p>
            <p>
                <label for="alamat">Alamat: </label>
                <textarea name="alamat"><?php echo $mahasiswa['alamat'] ?></textarea>
            </p>
            <p>
                <label for="jenis_kelamin">Jenis Kelamin: </label>
                <?php $jk = $mahasiswa['jenis_kelamin']; ?>
                <label><input type="radio" name="jenis_kelamin" value="laki-laki" <?php echo ($jk == 'laki-laki') ? "checked" : "" ?>> Laki-laki</label>
                <label><input type="radio" name="jenis_kelamin" value="perempuan" <?php echo ($jk == 'perempuan') ? "checked" : "" ?>> Perempuan</label>
            </p>
            <p>
                <label for="agama">Agama: </label>
                <?php $agama = $mahasiswa['agama']; ?>
                <select name="agama">
                    <option <?php echo ($agama == 'Islam') ? "selected" : "" ?>>Islam</option>
                    <option <?php echo ($agama == 'Kristen') ? "selected" : "" ?>>Kristen</option>
                    <option <?php echo ($agama == 'Hindu') ? "selected" : "" ?>>Hindu</option>
                    <option <?php echo ($agama == 'Budha') ? "selected" : "" ?>>Budha</option>
                    <option <?php echo ($agama == 'Atheis') ? "selected" : "" ?>>Atheis</option>
                </select>
            </p>
            <p>
                <input type="submit" value="Simpan" name="simpan" />
            </p>

        </fieldset>


    </form>

</body>

</html>