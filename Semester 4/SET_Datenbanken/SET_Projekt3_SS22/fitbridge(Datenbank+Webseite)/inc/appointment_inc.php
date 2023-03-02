<?php
include("php_sql_inc.php");
session_start(); //Needed for session variable containing userid
echo "<h2>Anfrage wird bearbeitet!</h2>";
echo "<br>";
$userId = $_SESSION["userid"]; //Current (logged in) users id from session var
$name = $_SESSION["firstname"]; //Name of currently logged in individual
$appointment_date = date('Y-m-d', strtotime($_POST['appointment_date'])); //Date entered by customer
$appointment_trainerName = $_POST['user']; //Name entered by customer
$appointment_info = $_POST['appointment_info']; //Info entered by customer
$appointment_time = $_POST['appointment_time']; //Time entered by customer
$_SESSION["warning"] = 0; //In case user books appointment in past
if ($appointment_trainerName=='') {
    //Don't submit to table, notify user of empty fields
    //Goes back to the user site...
    $_SESSION["warning"] = 2;
    header("Location: ../appointment.php");
    exit();
} else if ($appointment_date<date('Y-m-d')) {
    $_SESSION["warning"]=3;
    header("Location: ../appointment.php");
    exit();
} else { //Submit form etc.
    //Get username from users table:
    $loggedInUsername = fitBridge_getUserInfo(1, $userId, "username");
    $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
    //Add appointment with information entered in form:
    $cErr = fitBridge_addApt($appointment_date, $appointment_time, $appointment_trainerName, $loggedInUsername, $appointment_info);
    if ($cErr==4) {
        $_SESSION["warning"] = 4;
    } else {
        $_SESSION["warning"] = 21;
    }
}
//Goes back to the user site...
header("Location: ../appointment.php");
exit();
$stmt->close();
$conn->close();