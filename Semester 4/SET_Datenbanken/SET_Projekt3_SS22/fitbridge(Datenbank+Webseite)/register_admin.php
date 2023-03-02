<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="style.css" rel="stylesheet" type="text/css"/>
    <script src="header.js" type="text/javascript" defer></script>
</head>
<style>
    p {
        font-family: Arial;
        color: green;
        font-size: 15px;
    }
    .appointmentForm {
        position: absolute;
        top: 20%;
        left: 5%;
        width: 750px;
        height: 80%;
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
        margin-left: 30%;
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
        font-size: 15px;
    }
</style>
<body style="background-image: url('img/risen-wang-20jX9b35r_M-unsplash_COPY.jpg');">
<div class="appointmentForm">
    <h1 style="margin-left: 3%">Registrierung</h1>
    <div style="width:100%; height:10%">
        <?php
        session_start();
        if (isset($_SESSION["warning"]) && $_SESSION["warning"] == 2) {
            echo "<p>Bitte keine Felder Leer lassen!</p>";
            $_SESSION["warning"] = 0;
        } else if (isset($_SESSION["warning"]) && $_SESSION["warning"] == 1) {
            echo "<p>Geburtsdatum unplausibel!</p>";
            $_SESSION["warning"] = 0;
        } else if (isset($_SESSION["warning"]) && $_SESSION["warning"] == 4) {
            echo "<p>Benutzername gibt es schon!</p>";
            $_SESSION["warning"] = 0;
        }
        ?>
    </div>
    <div style="height:90%; width:100%">
        <form action="inc/registration_inc_admin.php" method="post">
            <div style="top:10%">
                <p>Vorname</p>
                <input type="text" class="form-control" name="firstname" id="firstname">
            </div>
            <div style="top:20%">
                <p>Nachname</p>
                <input type="text" class="form-control" name="lastname" id="lastname">
            </div>
            <div style="top:30%">
                <p>Benutzername</p>
                <input type="text" class="form-control" name="username" id="username">
            </div>
            <div style="top:40%">
                <p>Passwort</p>
                <input type="password" class="form-control" name="password" id="password">
            </div>
            <div style="top:50%">
                <p>Geburtsdatum</p>
                <input type="date" class="form-control" name="birthday" id="birthday"/>
            </div>
            <div style="top:60%; height:20%">
                <p>Über mich:</p>
                <input style="top:10%" type="text" class="form-control" name="about" id="about"/>
            </div>
            <div style="left:6%; top:82%; height: 10%">
                <input type="submit" style="margin-left:5%; width:100%;height:100%">
            </div>
        </form>

    </div>
</div>
</body>
</html>