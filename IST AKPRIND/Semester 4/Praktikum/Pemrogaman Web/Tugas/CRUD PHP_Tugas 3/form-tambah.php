<?php include("koneksi.php"); ?>

<!DOCTYPE html>
<html>

<head>
    <title>Penambahan Mahasiswa</title>
</head>

<body>
    <header>
        <h3>Mahasiswa<h3>
    </header>

    <form action="proses-tambah.php" method="POST">

        <fieldset>

            <p>
                <label for="nama">Nama: </label>
                <input type="text" name="nama" placeholder="nama lengkap" />
            </p>
            <p>
                <label for="nim">NIM: </label>
                <input type="text" name="nim" placeholder="isikan nim" />
            </p>
            <p>
                <label for="alamat">Alamat: </label>
                <textarea name="alamat"></textarea>
            </p>
            <p>
                <label for="jenis_kelamin">Jenis Kelamin: </label>
                <label><input type="radio" name="jenis_kelamin" value="laki-laki"> Laki-laki</label>
                <label><input type="radio" name="jenis_kelamin" value="perempuan"> Perempuan</label>
            </p>
            <p>
                <label for="agama">Agama: </label>
                <select name="agama">
                    <option>Islam</option>
                    <option>Kristen</option>
                    <option>Hindu</option>
                    <option>Budha</option>
                    <option>Atheis</option>
                </select>
            </p>
            <p>
                <input type="submit" value="Tambah" name="tambah" />
            </p>

        </fieldset>

    </form>

</body>

</html>