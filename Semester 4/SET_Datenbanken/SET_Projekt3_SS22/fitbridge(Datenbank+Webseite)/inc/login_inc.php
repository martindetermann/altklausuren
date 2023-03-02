<?php
include("php_sql_inc.php");
/**
 * FitBridge
 *
 * This php script is used by an html form to log users into the FitBridge system.
 *
 * The script receives a username and password. It then connects to the "users" database,
 * and executes two queries to
 *   (1) verify user exists, and
 *   (2) check if password matches.
 * If either (1) or (2) fails, user is redirected back to login page.
 * If login is successful, the key id associated with the entered username is stored as a session
 * variable, to be used by other scripts (user is logged in). Depending on the type of user
 * (type=0: customer, type=1: trainer, type=2: admin) user is redirected to the corresponding
 * site.
 *
 * @param $username username entered in HTML form, and Posted here
 * @param $password password entered in HTML form, and Posted here
 * @session qtyOfAppointments stores quantity of appointments associated with user, to display on user_page
 * @session userid stores the key id associated with user, if user logs in successfully
 * @session pastDateWarning is used by user_page and appointment to warn users if appointments are duplicate or past
 *
 * @return 0 in all cases, all error possibilities are covered within the function using redirects.
 *
 * @throws popupwarning_inc if popups are blocked, and redirect fails. Just informs user and gives link to redirect.
 *
 * @query $sql = "select * from users where username like '%$username%'" pulls rows with username similar to the one entered in form
 *
 * @throws connect_error if connection to server fails
 * @author  Ahmed Sabti, Martin Determann, Bland Azad Saleem, Othmane Kribia
 * @license Only to be used by Fitness24 as permitted by contract [LINK TO CONTRACT]
 */

session_start(); //To store session variable
$username = $_POST['username']; //Users Username
$password = $_POST['password']; //Users Password
$_SESSION['qtyOfAppointments'] = 0; //To be used later
$_SESSION["pastDateWarning"] = 0; //To be used later
$_SESSION["blankFields"] = 0; //To be used later
//Connect to the database:
$conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
if ($conn->connect_error) { //If connection fails
    echo "<h2>Verbindung Fehlgeschlagen!</h2>"; //Notify user
    die('Connection failed : ' . $conn->connect_error); //Kill connection, display error
} else { /*Connection succeeded, verify information and respond accordingly*/
    $sql = "select * from users where username like '$username'"; /*Check if user exists using SQL Query*/
    $result = $conn->query($sql); /*Store the entire result (all users with similar username) in variable $result*/
    if ($result->num_rows > 0) { /*If there is at least one user (there can't be more than one, see register_inc)*/
        foreach ($result as $row) { //Parse the result into a row
            if ($row["password"] == $password) { //if password matches
                $_SESSION["userid"] = $row["id"]; /*store the users id (key id) as a session variable for later use*/
                $_SESSION["firstname"] = $row["name"]; /*store the users first name as a session variable for later use*/
                $_SESSION["this_username"] = $row["username"];
                if ($row["type"] == 0) { /*If user's type=0, user is a customer*/
                    $_SESSION["type"] = 0;
                    echo "Erfolg! Sie wurden eingeloggt"; /*Notify user that they have been logged in*/
                    //In case pop ups are disabled prints error message:
                    include 'popupwarning_inc.php';
                    echo "<a href='../user_page.php'>oder clicke hier um weiter zu gehen</a>";
                    header("Location: ../user_page.php");
                    exit();
                } else if ($row["type"] == 1) { /*If user's type=1, user is a trainer*/
                    $_SESSION["type"] = 1;
                    //In case pop ups are disabled prints error message:
                    include 'popupwarning_inc.php';
                    echo "<a href='../trainer_page.php'>oder clicke hier um weiter zu gehen</a>";
                    header("Location: ../trainer_page.php");
                    exit();
                } else if ($row["type"] == 2) { /*If user's type=2, user is an admin*/
                    $_SESSION["type"] = 2;
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
                    return 0;
                }
            } else { //If password is wrong
                echo "Passwort ist falsch!"; //Notify user
                echo "<a href='../login.html'>try again</a>"; //Go back to login
                return 0;
            }
        }
    } else { //Account doesn't exist
        echo "Benutzername ist falsch oder existiert nicht!";
        echo "<a href='../login.html'>try again</a>";
    }
}
$conn->close(); //and close connection to db
return 0;
?>