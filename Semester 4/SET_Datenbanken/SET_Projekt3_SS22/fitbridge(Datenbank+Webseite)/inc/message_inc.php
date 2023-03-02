<?php
include("php_sql_inc.php");
session_start(); //Needed for session variable containing userid
if (($_POST['username'] == '') | ($_POST['message_text'] == '')) {
    //Don't submit to table, notify user of empty fields
    //Goes back to the user site...
    $_SESSION["pastDateWarning"] = 2;
    header("Location: ../message.php");
    exit();
}
echo "<h2>Nachricht wird bearbeitet!</h2>";
echo "<br>";
$userId = $_SESSION["userid"]; //Current (logged in) users id from session var
$message_date = date('Y-m-d'); //Current date
$message_time = date('H:i:s'); //Current time
$message_receiver = $_POST['username']; //username of receiver entered by customer
$message_text = $_POST['message_text']; //Info entered by customer

//Database connection
$conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
if ($conn->connect_error) { //Connection fails
    echo "<h2>Verbindung Fehlgeschlagen!<br></h2>"; //Inform user
    echo "<h2>Die Verbindung zu unserem Server ist fehlgeschlagen. Kontaktieren Sie unseren Helpdesk!<br></h2>";
    echo "<a href='../user_page.php'>zurück gehen</a>"; //Go back to previous page
    die('Connection failed : ' . $conn->connect_error); //Print connection error type
} else { /*Connection succeeded, Insert appointment with userid into the appointments table*/
    //Get username of the sender (from session variable containing userid)
    $message_sender = fitBridge_getUserInfo(1, $userId, "username");
    //Send message
    $cErr = fitBridge_sendMessage($message_sender, $message_receiver, $message_date, $message_time, $message_text);
    //Goes back to the user site...
    header("Location: goback_inc.php");
    exit();
}
$stmt->close();
$conn->close();