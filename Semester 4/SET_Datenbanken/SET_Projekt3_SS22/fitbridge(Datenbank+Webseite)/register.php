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
    .appointmentForm {
        position: absolute;
        top: 25%;
        left: 10%;
        width: 750px;
        height: 75%;
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
    <div>
        <?php
        session_start();
        if (isset($_SESSION["warning"]) && $_SESSION["warning"]==2) {
            echo "<p>Bitte keine Felder Leer lassen!</p>";
            $_SESSION["warning"]=0;
        } else if (isset($_SESSION["warning"])&&$_SESSION["warning"]==1) {
            echo "<p>Geburtsdatum unplausibel!</p>";
            $_SESSION["warning"]=0;
        } else if (isset($_SESSION["warning"])&&$_SESSION["warning"]==3) {
            echo "<p>IBAN ist zu kurz!</p>";
            $_SESSION["warning"]=0;
        } else if (isset($_SESSION["warning"])&&$_SESSION["warning"]==4) {
            echo "<p>Benutzername existiert schon!</p>";
            $_SESSION["warning"]=0;
        }
        ?>
    </div>
    <div style="height:90%; width:100%">
        <form action="inc/registration_inc.php" method="post">
            <div style="top:10%">
                <p>Vorname</p>
                <input type="text" class="form-control" name="firstname" id="firstname">
            </div>
            <div style="top:23%">
                <p>Nachname</p>
                <input type="text" class="form-control" name="lastname" id="lastname">
            </div>
            <div style="top:36%">
                <p>Benutzername</p>
                <input type="text" class="form-control" name="username" id="username">
            </div>
            <div style="top:48%">
                <p>Passwort</p>
                <input type="password" class="form-control" name="password" id="password"></textarea>
            </div>
            <div style="top:62%">
                <p>Geburtsdatum</p>
                <input type="date" class="form-control" name="birthday" id="birthday"/>
            </div>
            <div style="top:76%">
                <p>IBAN</p>
                <input type="string" class="form-control" name="IBAN" id="IBAN"/>
            </div>
            <div style="left:6%; top:82%; height: 10%">
                <input type="submit" style="margin-left:5%; width:100%;height:100%">
            </div>
        </form>
    </div>

</div>
</body>
</html>