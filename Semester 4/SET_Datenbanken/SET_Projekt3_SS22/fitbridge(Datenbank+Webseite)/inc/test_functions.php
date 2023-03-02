<?php
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SOFTWARE/FUNCTION TESTS FOR SQL RELATED FUNCTIONS PERFORMED HERE TO SIMPLIFY IMPLEMENTATION/////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
include("php_sql_inc.php");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ABLAUF: ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 1) add valid user "Bob Jeffries" to users table using fitBridge_addUser();
/// 2) add valid user "Trainer TT" to users table using fitBridge_addUser();
/// 3) attempt to add identical user (same username) using fitBridge_addUser();
/// 4) search for "Bob Jeffries" in users table using fitBridge_getUserInfo;
/// 5) search for nonexistent user using fitBridge_getUserInfo();
/// 6) search with invalid parameters using fitBridge_getUserInfo();
/// 7) Create an appointment using Bob and Trainer's infos
/// 8) Create a second valid appointment
/// 9) Attempt to create an identical appointment
/// 10) Search for all appointments belonging to Ttrainer (by username)
/// 11) Display all appointments belonging to Ttrainer using displayAppointments()
/// 12) Send a mail from Ttrainer to Bob Jeffries (by usernames)
/// 13) Search for mail as Bob Jeffries (by Bob's Username)
/// 14) Mark message as deleted by Bob's username
/// 15) Search for the deleted message as Bob post deletion
/// 16) Delete message as trainer
/// Clean all tables

//1) Create a new customer in users table
echo "Creating Bob Jeffries as a valid user with fitBridge_addUser<br>";
$firstname = "BOB";
$lastname = "Jeffries";
$username = "b.j_user";
$password = "password";
$birthday = "0";
$type = 0;
$iban = "DE111233232323232323232";
$about = "I AM BOB!!";
$cErr = fitBridge_addUser($firstname, $lastname, $username, $password, $birthday, $type, $iban, $about);
echo $cErr;
echo " is the return value from adding Bob (should be 0)<br>";

//2) Create a new trainer in users table
echo "Creating a new trainer in users table with _addUser:<br>";
$firstname = "Trainer";
$lastname = "TT";
$trainerUsername = "trainerusername";
$password = "pwd";
$birthday = "0";
$type = 1;
$iban = "";
$about = "I AM TRAINER!!";
$cErr = fitBridge_addUser($firstname, $lastname, $trainerUsername, $password, $birthday, $type, $iban, $about);
echo $cErr;
echo " is the result from creating a new trainer in users table with _addUser:<br>";

//3) Attempt to create identical trainer in users table
echo "Trying to create an identical trainer in users table with _addUser:<br>";
$cErr = fitBridge_addUser($firstname, $lastname, $trainerUsername, $password, $birthday, $type, $iban, $about);
echo $cErr;
echo " is the result from creating an identical trainer in users table with _addUser:<br>";

//4) Get the Bob Jeffries (user created in step 1) infos back
echo "Searching for all Bob's info from table using fitBridge_getUserInfo:<br>";
$testFirstname = fitBridge_getUserInfo('username', "b.j_user", "name");
$testLastname = fitBridge_getUserInfo('username', "b.j_user", "lastname");
$testUsername = fitBridge_getUserInfo('username', "b.j_user", "username");
$testPassword = fitBridge_getUserInfo('username', "b.j_user", "password");
$testBirthday = fitBridge_getUserInfo('username', "b.j_user", "birthday");
$testType = fitBridge_getUserInfo('username', "b.j_user", "type");
$testIban = fitBridge_getUserInfo('username', "b.j_user", "IBAN");
$testAbout = fitBridge_getUserInfo('username', "b.j_user", "about");
echo $testFirstname, $testLastname, $testUsername, $testPassword, $testBirthday, $testType, $testIban, $testAbout;
echo " were the results from searching for Bob's info with _getUserInfo()<br>";

//5) Do a false search
echo "Conducting search for nonexistent user:<br>";
$testFirstname = fitBridge_getUserInfo('username', "nonexistent.username", "name");
echo $testFirstname;
echo " were the results from searching for a nonexistent user with _getUserInfo()<br>";

//6) Search with inaccurate parameters
echo "Conducting search for nonexistent user:<br>";
$testFirstname = fitBridge_getUserInfo(4, "nonexistent.username", "name");
echo $testFirstname;
echo " were the results from searching with invalid parameters with _getUserInfo()<br>";

//7) Create an appointment using Bob and Trainer's infos
echo "Trying to create an appointment in appointments table with _addApt:<br>";
$date1 = date('Y-m-d');
$time1 = "20:25:20";
$customerUsername = "b.j_user";
$trainerUsername = "trainerusername";
$info = "SICK APPOINTMENT";
$cErr = fitBridge_addApt($date1, $time1, $trainerUsername, $customerUsername, $info);
echo $cErr;
echo " is the result from creating valid appointment with _addApt:<br>";

//8) Creating a second valid appointment
echo "Trying to create a 2nd appointment in appointments table with _addApt:<br>";
$date2 = date('Y-m-d');
$time2 = "00:00:00";
$info2 = "second appointment";
$cErr = fitBridge_addApt($date2, $time2, $trainerUsername, $customerUsername, $info2);
echo $cErr;
echo " is the result from creating a second valid appointment with _addApt:<br>";

//9) Create an identical appointment
echo "Trying to create an identical appointment in appointments table with _addApt:<br>";
$cErr = fitBridge_addApt($date1, $time1, $trainerUsername, $customerUsername, $info);
echo $cErr;
echo " is the result from creating identical appointment with _addApt:<br>";

//10) Search for all appointments belonging to Ttrainer (by username)
echo "Trying to search for appointment in appointments table with fitBridge_getAptInfo:<br>";
$trainersDates = fitBridge_getAptInfo(2,$trainerUsername,"date");
$trainersTimes = fitBridge_getAptInfo(1,$customerUsername,"time");
$trainersCustomerUsernames = fitBridge_getAptInfo(2,$trainerUsername,"username_customer");
$trainersInfos = fitBridge_getAptInfo(1,$customerUsername,"info");
echo $trainersDates[0], $trainersTimes[0], $trainersCustomerUsernames[0], $trainersInfos[0];
echo "<br>";
echo $trainersDates[1], $trainersTimes[1], $trainersCustomerUsernames[1], $trainersInfos[1];
echo "<br>";
echo "the above should contain all of the trainers appointments";
echo "<br>";

//11) Display all appointments belonging to Ttrainer using displayAppointments()
echo "<table>";
fitBridge_displayAppointments("Trainer");
echo "</table>";

//12) Send a mail from Ttrainer to Bob Jeffries (by usernames)
echo "Trying to send message from Ttrainer to Bob Jeffries (by username) with fitBridge_sendMessage:<br>";
$message = "Hello customer!";
$cErr = fitBridge_sendMessage($trainerUsername, $customerUsername, date('Y-m-d'), strftime('H:i:s'), $message);
echo $cErr, " is the result from sending message from Ttrainer to Bob...<br>";

//13) Search for mail as Bob Jeffries (by Bob's Username)
echo "Trying to search for message from Ttrainer to Bob Jeffries (by username) with fitBridge_getMessageInfo:<br>";
$messageSender = fitBridge_getMessageInfo(2, $customerUsername, "sender");
$messageDate = fitBridge_getMessageInfo(2, $customerUsername, "date");
$messageTime = fitBridge_getMessageInfo(2, $customerUsername, "time");
$messageMessage = fitBridge_getMessageInfo(2, $customerUsername, "message");
echo $messageSender[0], $messageDate[0], $messageTime[0], $messageMessage[0];
echo "<br> ^^ are results from searching for the message <br>";

//14) Mark message as deleted by Bob's username
echo "Trying to mark message as deleted by Bob with fitBridge_markAsDeleted():<br>";
$cErr = fitBridge_markAsDeleted($messageTime[0], $messageDate[0], $messageSender[0], 2);
echo $cErr;
echo " is the result from marking as deleted<br>";

//15) Search for the deleted message as Bob post deletion
$sSender = "sender";
$sDate = "date";
$sTime = "time";
$sMessage = "message";
echo "Trying to search for message from Ttrainer to Bob Jeffries POST DELETION (by username) with fitBridge_getMessageInfo:<br>";
$messageSender2 = fitBridge_getMessageInfo(1, $customerUsername, $sSender);
$messageDate2 = fitBridge_getMessageInfo(1, $customerUsername, $sDate);
$messageTime2 = fitBridge_getMessageInfo(1, $customerUsername, $sTime);
$messageMessage2 = fitBridge_getMessageInfo(1, $customerUsername, $sMessage);
echo $messageSender2[0], $messageDate2[0], $messageTime2[0], $messageMessage2[0];
echo "<br> ^^ are results from searching for the DELETED message (should be 2222) <br>";

//16) Delete message as trainer
echo "Trying to delete message with fitBridge_deleteMessage():<br>";
echo "Message sender:", $messageSender[0], "<br>";
$cErr = fitBridge_deleteMessage($messageTime[0], $messageDate[0], $messageSender[0]);
echo $cErr;
echo " is the result from message being deleted<br>";


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CLEAN TABLE AFTER RUNNING TESTS ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Delete appointments
echo "deleting 2 appointments <br>";
$cErr = fitBridge_deleteApt($time1, $date1, $trainerUsername);
$cErr = fitBridge_deleteApt($time2, $date2, $trainerUsername);
echo $cErr;
echo " is the result from deleting 2 appointments <br>";

//Delete nonexistent appointments
echo "deleting nonexistent appointment <br>";
$cErr = fitBridge_deleteApt($time2, $date2, $trainerUsername);
echo $cErr, " is the result from deleting nonexistent appointment <br>";

//Delete users
echo "deleting 2 users <br>";
$cErr = fitBridge_deleteUser($testUsername);
$cErr = fitBridge_deleteUser($trainerUsername);
echo $cErr;
echo " is the result from deleting 2 users<br>";

//Delete nonexistent users
echo "deleting 2 nonexistent users <br>";
$cErr = fitBridge_deleteUser($testUsername);
$cErr = fitBridge_deleteUser($trainerUsername);
echo $cErr;
echo " is the result from deleting 2 nonexistent users<br>";

//Test if browser really refreshed form
echo "updated??";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

