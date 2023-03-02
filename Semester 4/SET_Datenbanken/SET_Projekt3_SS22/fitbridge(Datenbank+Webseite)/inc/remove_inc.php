<?php
include("php_sql_inc.php");
/**
 * FitBridge
 *
 * This php script is currently being used to delete users and trainers from the users table in the FitBridge DB,
 * based on their name/username. It then redirects back to the admin page, after script is completed, assuming there
 * are no errors.
 *
 * @param $input contains the name/username of the user to be deleted
 * @param $basedOn contains the info on whether or not user should be deleted by name or username
 * @function removeFromTable removes the user from table based on name and or username and type (see below)
 *
 * @author  Ahmed Sabti, Martin Determann, Bland Azad Saleem, Othmane Kribia
 * @license Only to be used by Fitness24 as permitted by contract [LINK TO CONTRACT]
 */
$input = $_POST['user']; //Name of trainer to be deleted
$basedOn = $_POST['topic']; //Type of form being submitted
if ($basedOn=="customer"){ //Delete customer by username
    removeFromTable(0, $input, 0);
} else {
    removeFromTable($input, 0, 1); //Delete trainer by username
}
include 'popupwarning_inc.php';
echo "<a href='../admin_page.php'>oder clicke hier um weiter zu gehen</a>";
header("Location: ../admin_page.php");
exit();

/**
 * The removeFromTable function conducts an SQL query to remove a user based on name and or username and type (0=customer
 * 1=trainer, 2=admin). Enter '0' in the name OR username fields if you do not with to use these. Type field and at least
 * one of the other fields must be defined.
 * @param $name describes the name of the user to be deleted
 * @param $username describes the username of the user to be deleted
 * @param $type describes the type of user (0=customer, 1=trainer, 2=admin)
 * @return bool|int|mysqli_result|void -1 if params not passed correctly, otherwise return mysqli result
 */
function removeFromTable($name, $username, $type)
{
    $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
    if ($conn->connect_error) { //If connection fails
        echo "<h2>Verbindung Fehlgeschlagen!</h2>"; //Notify user
        die('Connection failed : ' . $conn->connect_error); //Kill connection, display error
    } else { /*Connection succeeded, verify information and respond accordingly*/
        if (($name == 0) && ($username != 0)) { //Delete by username, ignore name
            $sql = "DELETE FROM `users` WHERE `username` LIKE '$username' AND `type` LIKE '$type'"; /*Delete selected trainer with that username*/
            $result = $conn->query($sql); /*Store the entire result (all users with similar username) in variable $result*/
            fitBridge_deleteMessage(1,1,$username);
            fitBridge_deleteApt(1,1,$username);
        } elseif (($name != 0) && ($username == 0)) { //Delete by name, ignore username
            $sql = "DELETE FROM `users` WHERE `name` LIKE '$name' AND `type` LIKE '$type'"; /*Delete selected trainer with that name*/
            $result = $conn->query($sql); /*Store the entire result (all users with similar username) in variable $result*/
            fitBridge_deleteMessage(1,1,$username);
            fitBridge_deleteApt(1,1,$username);
        } elseif (($name != 0) && ($username != 0)) { //Delete by name and username
            $sql = "DELETE FROM `users` WHERE `name` LIKE '$name' AND `type` LIKE '$type' AND `username` LIKE '$username'"; /*Delete selected trainer with that name*/
            $result = $conn->query($sql); /*Store the entire result (all users with similar username) in variable $result*/
            fitBridge_deleteMessage(1,1,$username);
            fitBridge_deleteApt(1,1,$username);
        } else {
            $result = -1;
        }
    }
    $conn->close(); //and close connection to db
    return $result;
}

