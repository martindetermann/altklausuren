<!DOCTYPE html>

<html>
<?php
/**
 * Check if user is logged in and has rights to access this page:
 */
session_start();
include("inc/php_sql_inc.php");
    if (!isset($_SESSION["type"]) | $_SESSION["type"]!=2){
        header("Location: inc/goback_inc.php");
        exit();
        return;
    }
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <script src="header_loggedintrainer.js" type="text/javascript" defer></script>
</head>
<style>
    .display {
        position: absolute;
        top: 30%;
        left: 49%;
        width: 45%;
        background-color: black;
        opacity: 0.9;
    "
    }

    .display div {
        width: 100%;
        font-family: Arial;
        background-color: greenyellow;
        color: black;
        font-size: 100%;
    }

    .display h1 {
        font-family: Arial;
        font-size: 150%;
        font-weight: bold;
        color: greenyellow;
    }

    .showAppointments {
        position: absolute;
        top: 20%;
        left: 5%;
        width: 600px;
        height: 80%;
        background-color: black;
        opacity: 0.9;
        font-family: Arial;
    }

    .showAppointments table {
        position: absolute;
        text-decoration: none;
        font-weight: normal;
        font-size: 100%;
        width: 90%;
        top: 20%;
        left: 5%;
        background-color: greenyellow;
        color: greenyellow;
    }

    .showAppointments table td {
        width: 5%;
        background-color: black;
        border-color: black;
        border-style: outset;
    }

    .showAppointments table tr {
        height: 10%;
    }

    .showAppointments h1 {
        position: absolute;
        font-size: 150%;
        font-weight: bold;
        color: greenyellow;
    }

    .showAppointments table select {
        width: 100%;
        background-color: greenyellow;
        border-color: black;
        border-style: outset;
    }

    .clicker {
        background-color: greenyellow;
        color: black;
        outline: none;
        cursor: pointer;
    }

    .hiddendiv {
        display: none;
        background-color: greenyellow;
    }

    .clicker:focus + .hiddendiv {
        display: block;
    }
    input {
        background-color:greenyellow;
        color:black;
        font-family: Arial;
        font-size:15px;
    }
</style>
<body style="background-image: url('img/risen-wang-20jX9b35r_M-unsplash_COPY.jpg');">
<div style="position:absolute; top:20%; right:5%; background-color:black; height:10%; width:10%">
    <p style="color:greenyellow; font-family: arial">eingeloggt als:</p>
    <?php
    /**
     * Get and display first name from session variable
     */
    if (isset($_SESSION["firstname"])){
        echo "<p style='color:greenyellow; font-family: Arial; font-weight: bolder'>";
        echo $_SESSION["firstname"];
        echo "</p>";
    } else {
        echo "<h1 style='color:greenyellow'>";
        echo "?";
        echo "</h1>";
    }
    ?>
</div>
<div class="showAppointments" style="position:absolute; left:5%; top:100%">
    <h1 style="top:5%;left:31%">Nachrichten</h1>
    <table>
        <tr>
            <td>Von</td>
            <td>An</td>
            <td>Datum</td>
            <td>Uhrzeit</td>
            <td>Nachricht</td>
        </tr>
        <?php
        fitBridge_displayMessagesAsTable();
        ?>
    </table>
    <h1 style="top:80%; color:greenyellow; font-family: arial">Nachrichten entfernen</h1>
    <form style="position:absolute; top:90%" action="inc/removemessage_inc.php" method="post">
        <?php
        fitBridge_displayMessagesAsInputs();
        ?>
    </form>
</div>

<div class="showAppointments">
    <h1 style="top:5%;left:5%">Übersicht aller Gebuchten Termine im system</h1>
    <table>
        <tr>
            <td>Trainer</td>
            <td>Kunde</td>
            <td>Datum</td>
            <td>Uhrzeit</td>
            <td>Sonstiges</td>
        </tr>
        <?php
        fitBridge_displayAppointments(1);
        ?>
    </table>
</div>
<div class="display">
    <div style="background-color:black">
        <h1>Trainer im System</h1>
    </div>
    <div>
        <?php
        //This is an integrated PHP Script that displays all trainers in system
        $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
        if ($conn->connect_error) {
            echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
            die('Connection failed : ' . $conn->connect_error);
        } else {
            $sql = "select * from users where type like '%1%'"; //QUERY: All users marked as trainers
            $result = $conn->query($sql); //Stored in result
            if ($result->num_rows > 0) { //If there were any trainers in the FitBridge database
                foreach ($result as $row) { //Display these trainers on the window
                    echo "<div>";
                    echo "<p style='font-weight:bold;'>";
                    echo $row["name"];
                    echo "</p>";
                    echo $row["about"];
                    echo "</div>";
                }
            } else {
                echo "<p>";
                echo "keine Trainer im System";
            }
        }
        ?>
    </div>
    <h1>Trainer aus System entfernen</h1>
    <div>
        <form action="inc/remove_inc.php" method="post" id="firstname">
            <select style="background-color:greenyellow; margin: 1%" list="trainers" name="user"/>
            <?php
            //This is an integrated PHP Script that displays all trainers in system
            $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
            if ($conn->connect_error) {
                echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
                die('Connection failed : ' . $conn->connect_error);
            } else {
                $sql = "select * from users where type like '%1%'"; //QUERY: All users marked as trainers
                $result = $conn->query($sql); //Stored in result
                if ($result->num_rows > 0) { //If there were any trainers in the FitBridge database
                    foreach ($result as $row) { //Display these trainers on website
                        echo "<option value='";
                        echo $row["name"];
                        echo "'>";
                        echo $row["name"];
                        echo "</option>";
                    }
                }
            }
            ?>
            <div>
                <input type="submit" value="Trainer Löschen"
                       style="background-color:black; color:greenyellow; margin:1%">
            </div>
        </form>
    </div>
</div>
<div class="display" style="position:absolute; top:80%">
    <div style="background-color:black">
        <h1>Kunden im System</h1>
    </div>
    <div>
        <?php
        //This is an integrated PHP Script that displays all trainers in system
        $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
        if ($conn->connect_error) {
            echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
            die('Connection failed : ' . $conn->connect_error);
        } else {
            $sql = "select * from users where type like '%0%'"; //QUERY: All users marked as customers
            $result = $conn->query($sql); //Stored in result
            if ($result->num_rows > 0) { //If there were any users in the FitBridge database
                foreach ($result as $row) { //Display these users on site
                    echo "<div>";
                    echo "<p style='font-weight:bold;'>";
                    echo $row["name"];
                    echo "</p>";
                    echo $row["username"];
                    echo "</div>";
                }
            } else {
                echo "<p>";
                echo "keine Benutzer im System";
            }
        }
        ?>
    </div>
    <div style="background-color:black">
        <h1>Kunden aus System entfernen</h1>
    </div>
    <div>
        <form action="inc/remove_inc.php" method="post">
            <input type="hidden" value="customer" name="topic" id="customer"/>
            <select style="background-color:greenyellow; margin: 1%" name="user">
                <?php
                //This is an integrated PHP Script that displays all trainers in system
                $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
                if ($conn->connect_error) {
                    echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
                    die('Connection failed : ' . $conn->connect_error);
                } else {
                    $sql = "select * from users where type like '%0%'"; //QUERY: All users marked as customer
                    $result = $conn->query($sql); //Stored in result
                    if ($result->num_rows > 0) { //If there were any trainers in the FitBridge database
                        foreach ($result as $row) { //Display these trainers on the window
                            echo "<option value='";
                            echo $row["username"];
                            echo "'>";
                            echo $row["name"];
                            echo "</option>";
                        }
                    }
                }
                ?>
            </select>
            <div>
                <input type="submit" value="Kunde Löschen"
                       style="background-color:black; color:greenyellow; margin:1%">
                <input type="hidden" id="formID" name="formID" value="customer">
            </div>
        </form>
    </div>
</div>
</body>
</html>