<?php
include("php_sql_inc.php");
    echo "<h2>Anfrage wird bearbeitet!</h2>"; //Notify user
    //Data received by form is stored into variables:
    $firstname = $_POST['firstname'];
    $lastname = $_POST['lastname'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $birthday = $_POST['birthday'];
    $type = 1; //For trainer type=1
    $about = $_POST['about']; /*additional information about trainers, to be displayed to customers*/
session_start();
if (($firstname == '') | ($lastname == '') | ($username == '') | ($password == '')) {
    $_SESSION["pastDateWarning"] = 2;
    header("Location: ../register_trainer.php");
    exit();
    return;
} else if ($birthday > date('Y-m-d')){
    $_SESSION["pastDateWarning"] = 1;
    header("Location: ../register_trainer.php");
    exit();
    return;
} else {
    $cErr = fitBridge_addUser($firstname, $lastname, $username, $password, $birthday, $type, '', $about);
    if ($cErr == 22) {
        $_SESSION["warning"] = 4; //Benutzername gibt es schon
        header("Location: ../register_trainer.php");
    }
    else {
        $_SESSION["warning"] = 0; //Benutzername gibt es schon
        header("Location: ../login.html");
    }
}
?>