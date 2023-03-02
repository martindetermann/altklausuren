<!DOCTYPE html>
<html>
<?php
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
        <h1>Nachricht senden</h1>
    </div>
    <form action="inc/message_inc.php" method="post">
        <div style="height:20%; top:10%">
            <p>Benutzername des Empfängers</p>
            <select name="username" style="height:50%; bottom:0">
                <?php
                //This is an integrated PHP Script that displays all trainers in system
                $conn = new mysqli('localhost', 'root', '', 'fitness_datenbank');
                if ($conn->connect_error) {
                    echo "<h2>Verbindung Fehlgeschlagen! Kontaktiere unseren Helpdesk!</h2>";
                    die('Connection failed : ' . $conn->connect_error);
                } else {
                    $sql = "select * from users"; //QUERY: All users marked as trainers
                    $result = $conn->query($sql); //Stored in result
                    if ($result->num_rows > 0) { //If there were any trainers in the FitBridge database
                        foreach ($result as $row) { //Display these trainers on website
                            echo "<option value='";
                            echo $row["username"];
                            echo "'>";
                            echo $row["username"];
                            echo "</option>";

                        }
                    }
                }
                ?>
            </select>
        </div>
        <div style="top:30%; height:20%">
            <p style="position:absolute; top:0;">Schreibe deine Nachricht</p>
            <br>
            <br>
            <textarea type="text" name="message_text" id="message_text" maxlength="600"
                      style="margin-left:5%;width:112%; background-color:greenyellow"></textarea>
        </div>
        <div style="top:70%; height:15%;">
            <input type="submit" style="position:absolute; left:-23%;width:100%;height:100%">
        </div>
    </form>
    <div style="bottom:3%; width:100%;">
        <?php
        if ($_SESSION["pastDateWarning"] == 2) { //In case user left a field blank on previous entry
            echo "<p>Bitte keine Felder leer lassen</p>"; //Notify user of blank blankFields
            $_SESSION["pastDateWarning"] = 0; //Clear session id
        }
        ?>
    </div>
</div>
</body>
</html>