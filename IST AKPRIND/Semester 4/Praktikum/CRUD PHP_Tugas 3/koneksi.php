<?php

$server = "127.0.0.1";
$username = "root";
$pass = "";
$dbname = "pemrogamanweb";


$koneksi = new mysqli($server, $username, $pass, $dbname);

// cara koneksi 1
if (!$koneksi) {
    die("Koneksi anda error" . $koneksi->connect_error);
}
