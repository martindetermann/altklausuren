<!DOCTYPE html>
<html>
<?php
include("inc/php_sql_inc.php");
session_start();
if (!isset($_SESSION["type"]) | $_SESSION["type"]!=1){
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
    .showAppointments {
        position: absolute;
        top: 20%;
        left: 10%;
        width: 600px;
        height: 80%;
        background-color: black;
        opacity: 0.9;
        font-family: Arial;
    }

    .showAppointments table {
        position: absolute;
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
    background-color:greenyellow;
    color:black;
    outline:none;
    cursor:pointer;
    }

    .hiddendiv{
    display:none;
    background-color:greenyellow;
    }
    .clicker:focus + .hiddendiv{
    display:block;
    }
</style>
<body style="background-image: url('img/risen-wang-20jX9b35r_M-unsplash_COPY.jpg');">
<div style="position:absolute; top:20%; left:45%; background-color:black; height:10%; width:10%">
    <p style="color:greenyellow; font-family: arial">eingeloggt als:</p>
    <?php
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
<div class="showAppointments" style="position:absolute; left:5%">
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
<div class="showAppointments" style="position:absolute;left:56%">
    <h1 style="top:5%;left:31%">Gebuchte Termine</h1>
    <table>
        <tr>
            <td>Kunde</td>
            <td>Datum</td>
            <td>Uhrzeit</td>
            <td>Zusätzliche Infos</td>
        </tr>
        <?php
        fitBridge_displayAppointments($_SESSION["this_username"]);
        ?>
    </table>
</div>
</body>
</html>