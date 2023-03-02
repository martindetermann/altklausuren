<?php
include("php_sql_inc.php");
/**
 * FitBridge
 *
 * This php script is used by an html form to change any users password.
 *
 * The script receives a username and the corresponding current (old) password, as well as a new password.
 * It then connects to the "users" table in the FitBridge database, and executes two queries to
 *   (1) verify user exists, and
 *   (2) check if password matches.
 * If either (1) or (2) fails, the user is redirected back to login page.
 * If login is successful, the key id associated with the entered username is stored as a session
 * variable, to be used by other scripts (user is logged in). The users password in the database is
 * also updated to match the newly entered password. Depending on the type of user
 * (type=0: customer, type=1: trainer, type=2: admin) user is redirected to the corresponding
 * site.
 *
 * @param $username username entered in HTML form
 * @param $newPassword new password for this user entered in HTML form
 * @param $oldPassword password entered in HTML form
 * @session qtyOfAppointments stores quantity of appointments associated with user, to display on user_page
 * @session userid stores the key id associated with user, if user logs in successfully
 * @session name stores the users first name for other programs
 *
 *
 * @return 0 in all cases, all error possibilities are covered within the function using redirects.
 *
 * @throws connect_error if connection to server fails
 *
 * @query $sql = "select * from users where username like '%$username%'" pulls rows with username similar to the one entered in form
 * @query $sql = "UPDATE `users` SET `password`='$newPassword' WHERE `username` LIKE '$username'" changes the selected users password to the newly entered one
 *
 * @throws popupwarning_inc if popups are blocked, and redirect fails. Just informs user and gives link to redirect.
 * @author  Ahmed Sabti, Martin Determann, Bland Azad Saleem, Othmane Kribia
 * @license Only to be used by Fitness24 as permitted by contract [LINK TO CONTRACT]
 */

session_start(); //To store session variable
if ($_POST['newPassword']=='') {
    //Don't submit to table, notify user of empty fields
    //Goes back to the user site...
    $_SESSION["pastDateWarning"] = 2;
    header("Location: ../changePassword.php");
    exit();
} else {
    $username = $_POST['username']; //Users Username
    $oldPassword = $_POST['oldPassword']; //Users Password
    $newPassword = $_POST['newPassword']; //New user pw
    $_SESSION['qtyOfAppointments'] = 0; //To be used later
//Connect to the database:
    $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
    if ($conn->connect_error) { //If connection fails
        echo "<h2>Verbindung Fehlgeschlagen!</h2>"; //Notify user
        die('Connection failed : ' . $conn->connect_error); //Kill connection, display error
    } else { /*Connection succeeded, verify information and respond accordingly*/
        $sql = "select * from users where username like '%$username%'"; /*Check if user exists using SQL Query*/
        $result = $conn->query($sql); /*Store the entire result (all users with similar username) in variable $result*/
        if ($result->num_rows > 0) { /*If there is at least one user (there can't be more than one, see register_inc)*/
            foreach ($result as $row) { //Parse the result into a row
                if ($row["password"] == $oldPassword) { //if password matches
                    $_SESSION["userid"] = $row["id"]; /*store the users id (key id) as a session variable for later use*/
                    $_SESSION["firstname"] = $row["name"]; /*store the users first name as a session variable for later use*/
                    $sql = "UPDATE `users` SET `password`='$newPassword' WHERE `username` LIKE '$username'";
                    $conn->query($sql);
                    if ($row["type"] == 0) { /*If user's type=0, user is a customer*/
                        echo "Success! You have been logged in!"; /*Notify user that they have been logged in*/
                        //In case pop ups are disabled prints error message:
                        include 'popupwarning_inc.php';
                        echo "<a href='../user_page.php'>oder clicke hier um weiter zu gehen</a>";
                        header("Location: ../user_page.php");
                        exit();
                    } else if ($row["type"] == 1) { /*If user's type=1, user is a trainer*/
                        //In case pop ups are disabled prints error message:
                        include 'popupwarning_inc.php';
                        echo "<a href='../trainer_page.php'>oder clicke hier um weiter zu gehen</a>";
                        header("Location: ../trainer_page.php");
                        exit();
                    } else if ($row["type"] == 2) { /*If user's type=2, user is an admin*/
                        //In case pop ups are disabled prints error message:
                        include 'popupwarning_inc.php';
                        echo "<a href='../admin_page.php'>oder clicke hier um weiter zu gehen</a>";
                        header("Location: ../admin_page.php");
                        exit();
                    } else {
                        /* In case type is not specified (this should never occurr, see register_inc pages)*/
                        echo "FEHLER: user type not specified, this user hasn't been registered property and must re-register<br>";
                        echo "Bitte kontaktiere unseren Helpdesk!<br>";
                        echo "<a href='../index.html'>gehe zurueck</a>";
                    }
                } else { //If password is wrong
                    echo "Passwort ist falsch! Falls du dein Passwort vergessen hast, schicke uns eine Email."; //Notify user
                    echo "<a href='../login.html'>try again</a>"; //Go back to login
                }
            }
        } else { //Account doesn't exist
            echo "account not found ";
            echo "<a href='../login.html'>try again</a>";
        }
    }
    $conn->close(); //and close connection to db
}
exit();