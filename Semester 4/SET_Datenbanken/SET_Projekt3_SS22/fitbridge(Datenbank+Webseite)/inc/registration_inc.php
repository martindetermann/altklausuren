<?php
include("php_sql_inc.php");
echo "<h2>Anfrage wird bearbeitet!</h2>"; //Notify user
//Data received by form is stored into variables:
$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];
$username = $_POST['username'];
$password = $_POST['password'];
$birthday = $_POST['birthday'];
$type = 0; //For customers type=0
$iban = $_POST['IBAN'];
session_start();
if (($firstname == '') | ($lastname == '') | ($username == '') | ($password == '')) {
    $_SESSION["warning"] = 2;
    header("Location: ../register.php");
    exit();
} else if ($birthday > date('Y-m-d')) {
    $_SESSION["warning"] = 1;
    header("Location: ../register.php");
    exit();
} else if (strlen($iban) < 22) {
    $_SESSION["warning"] = 3;
    header("Location: ../register.php");
    exit();
} else {
    $cErr = fitBridge_addUser($firstname, $lastname, $username, $password, $birthday, $type, $iban, '');
    if ($cErr == 22) {
        $_SESSION["warning"] = 4; //Benutzername gibt es schon
        header("Location: ../register.php");
    } else {
        $_SESSION["warning"] = 0; //Benutzername gibt es schon
        header("Location: ../login.html");
    }
}
return 0;
?>
