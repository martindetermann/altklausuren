<!DOCTYPE html>
<html>
<?php
include("inc/php_sql_inc.php");
session_start();
if (!isset($_SESSION["userid"])){
    header("Location: inc/goback_inc.php");
    exit();
    return;
}
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="style.css" rel="stylesheet" type="text/css"/>
    <script src="header_loggedintrainer.js" type="text/javascript" defer></script>
</head>
<style>
    .appointmentForm {
        position: absolute;
        top: 30%;
        left: 5%;
        width: 500px;
        height: 60%;
        background-color: black;
        font-family: Arial;
    }

    .appointmentForm h1 {
        font-size: 20px;
        font-weight: bold;
        color: greenyellow;
    }

    .appointmentForm p {
        positon: absolute;
        margin-left: 5%;
        top: 0;
        font-size: 15px;
        color: greenyellow;
    }

    .appointmentForm input {
        position: absolute;
        margin-left: 35%;
        top: 50%;
        width: 80%;
        height: 90%;
        background-color: greenyellow;
        color: black;
    }

    .appointmentForm select {
        position: absolute;
        margin-left: 35%;
        top: 50%;
        width: 80%;
        height: 90%;
        background-color: greenyellow;
        color: black;
    }

    .appointmentForm div {
        position: absolute;
        width: 80%;
        height: 5%;
        font-family: Arial;
        color: greenyellow;
        font-size: 120%;
    }

    .display {
        width: 100%;
        font-family: Arial;
        background-color: greenyellow;
        color: black;
        font-size: 100%;
    }
</style>
<body style="background-image: url('img/risen-wang-20jX9b35r_M-unsplash_COPY.jpg');">
<div class="appointmentForm">
    <div>
        <h1>Termin Buchen</h1>
    </div>
    <form action="inc/appointment_inc.php" method="post">
        <div style="top:10%">
            <p>Datum</p>
            <input type="date" class="form-control" name="appointment_date" id="appointment_date">
        </div>
        <div style="top:20%">
            <p>Uhrzeit</p>
            <select name="appointment_time" id="appointment_time">
                <option value="08:00:00">8:00</option>
                <option value="08:30:00">8:30</option>
                <option value="09:00:00">9:00</option>
                <option value="10:00:00">10:00</option>
                <option value="11:00:00">11:00</option>
                <option value="12:00:00">12:00</option>
                <option value="13:00:00">13:00</option>
                <option value="14:00:00">14:00</option>
                <option value="15:00:00">15:00</option>
                <option value="16:00:00">16:00</option>
                <option value="17:00:00">17:00</option>
            </select>
        </div>
        <div style="top:30%">
            <p>Trainer Name</p>
            <select name="user">
                <?php
                //This is an integrated PHP Script that displays all trainers in system. It is outdated and should be replaced
                $conn = new mysqli(fitBridge_getHostname(), fitBridge_getUsername(), fitBridge_getPassword(), fitBridge_getDatabase());
                if ($conn->connect_error) {
                    echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
                    die('Connection failed : ' . $conn->connect_error);
                } else {
                    $sql = "select * from users where type like '%1%'"; //QUERY: All users marked as trainers
                    $result = $conn->query($sql); //Stored in result
                    echo "<option></option>";
                    if ($result->num_rows > 0) { //If there were any trainers in the FitBridge database
                        foreach ($result as $row) { //Display these trainers on website
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
        </div>
        <div style="top:40%; height:10%">
            <p style="position:absolute; top:0;">Erzähle uns was du erreichen willst</p>
            <br>
            <input type="text" class="form-control" name="appointment_info" id="appointment_info" maxlength="60"
                   style="position:absolute; top:140%; left:-30%; width:112%">
        </div>
        <div style="top:65%; height:15%;">
            <input type="submit" style="position:absolute; left:-23%;width:100%;height:100%">
        </div>
    </form>
    <div style="bottom:8%; width:100%;">
        <?php
        if (isset($_SESSION["warning"])) {
            if ($_SESSION["warning"] == 3) {
                echo "<p>Termine in der Vergangenheit können nicht gebucht werden</p>"; //Notify user
                $_SESSION["warning"] = 0; //Clear session id
            } else if ($_SESSION["warning"] == 2) {
                echo "<p>Bitte keine Felder leer lassen</p>"; //Notify user
                $_SESSION["warning"] = 0; //Clear session id
            } else if ($_SESSION["warning"]==4){
                echo "<p>Dieser Termin ist bereits besetzt!</p>"; //Notify user
                $_SESSION["warning"] = 0; //Clear session id
            } else if ($_SESSION["warning"] == 21) {
                echo "<p>Termin wurde gebucht!</p>"; //Notify user
                $_SESSION["warning"] = 0; //Clear session id
            }
        }
        ?>
    </div>
</div>
<div style="position:absolute; top:30%; left:49%; width:45%; height:60%; background-color:black;">
    <div class="display" style="background-color:black">
        <h1 style="color:greenyellow; font-size:100%">Unsere Trainer</h1>
    </div>
    <?php
    //This is an integrated PHP Script that displays all trainers in system
    $conn = new mysqli('localhost', 'root', '', 'fitness_datenbank');
    if ($conn->connect_error) {
        echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
        die('Connection failed : ' . $conn->connect_error);
    } else {
        $sql = "select * from users where type like '%1%'"; //QUERY: All users marked as trainers
        $result = $conn->query($sql); //Stored in result
        if ($result->num_rows > 0) { //If there were any trainers in the FitBridge database
            foreach ($result as $row) { //Display these trainers on the window
                echo "<div class='display'>";
                echo "<p style='font-weight:bold;'>";
                echo $row["name"];
                echo "</p>";
                echo $row["about"];
                echo "</div>";
            }
        }
    }
    ?>
</div>
</body>
</html>