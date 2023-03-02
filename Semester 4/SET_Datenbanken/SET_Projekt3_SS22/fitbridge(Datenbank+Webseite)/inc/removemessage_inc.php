<?php
include("php_sql_inc.php");

$msg_time = $_POST["time"]; //Time of message being deleted
$msg_date = $_POST["date"]; //Date of message being deleted
$msg_sender = $_POST["sender"];
$msg_receiver = $_POST["receiver"];
session_start();
$userID = $_SESSION["userid"];
$loggedInUsername = fitBridge_getUserInfo(1,$userID,"username");
if ($loggedInUsername == $msg_sender) {
    fitBridge_markAsDeleted($msg_time, $msg_date, $msg_sender,1);
} else {
    fitBridge_markAsDeleted($msg_time, $msg_date, $msg_sender,2);
}
header("Location: goback_inc.php");
exit();

