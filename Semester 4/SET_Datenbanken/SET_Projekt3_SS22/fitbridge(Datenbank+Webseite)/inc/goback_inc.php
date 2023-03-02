<?php
include("php_sql_inc.php");
session_start();
if (!isset($_SESSION["userid"])) {
    echo "Du hast nicht die Berechtigung um auf dieser Seite zuzugreifen.";
    echo "<a href='../login.html'>logge dich ein.</a>";
} else if ($_SESSION["type"]==0 && isset($_SESSION["userid"])){
    header("Location: ../user_page.php");
    exit();
} else if ($_SESSION["type"]==1){
    header("Location: ../trainer_page.php");
    exit();
} else if ($_SESSION["type"]==2){
    header("Location: ../admin_page.php");
    exit();
} else {
    //Sollte eigentlich nicht auftreten
}
