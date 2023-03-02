<?php
include("php_sql_inc.php");
echo "<h2>Anfrage wird bearbeitet!</h2>"; //Notify user
//Data received by form is stored into variables:
$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];
$username = $_POST['username'];
$password = $_POST['password'];
$birthday = $_POST['birthday'];
$type = 2; //For admin type=2
$about = $_POST['about']; /*additional information about admin*/
session_start();
$_SESSION["warning"] = 0;
if (($firstname == '') | ($lastname == '') | ($username == '') | ($password == '')) {
    $_SESSION["warning"] = 2;
    header("Location: ../register_admin.php");
    exit();
    return;
} else if ($birthday > date('Y-m-d')) {
    $_SESSION["warning"] = 1;
    header("Location: ../register_admin.php");
    exit();
    return;
} else {
    $cErr = fitBridge_addUser($firstname, $lastname, $username, $password, $birthday, $type, '', $about);
    if ($cErr == 22) {
        $_SESSION["warning"] = 4; //Benutzername gibt es schon
        header("Location: ../register_admin.php");
    } else {
        header("Location: ../login.html");
    }
}