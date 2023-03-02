<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="style.css" rel="stylesheet" type="text/css" />
    <script src="header.js" type="text/javascript" defer></script>
</head>
<style>
    .appointmentForm{
        position:absolute;
        top:35%;
        left:10%;
        width:500px;
        height:50%;
        background-color: black;
        font-family:Arial;
    }
    .appointmentForm h1{
        font-size:20px;
        font-weight: bold;
        color:greenyellow;
    }
    .appointmentForm p{
        positon:absolute;
        margin-left:5%;
        top:0;
        font-size:15px;
        color:greenyellow;
    }
    .appointmentForm input{
        position:absolute;
        margin-left:35%;
        top:50%;
        width:80%;
        height:90%;
        background-color:greenyellow;
        color:black;
    }
    .appointmentForm div{
        position:absolute;
        width: 80%;
        height:5%;
        font-family: Arial;
        color:greenyellow;
        font-size: 15px;
    }
</style>
 <body style="background-image: url('img/risen-wang-20jX9b35r_M-unsplash_COPY.jpg');">
  <div class="appointmentForm">
    <h1 style="margin-left: 5%">Password ändern</h1>
    <form action="inc/changepassword_inc.php" method="post">
        <div style="top:20%">
            <p>Benutzername:</p>
            <input type="text" name="username">
        </div>
        <div style="top:40%">
            <p>Altes Passwort:</p>
            <input type="password" name="oldPassword">
        </div>
        <div style="top:60%">
            <p>Neues Passwort:</p>
            <input type="password" name="newPassword">
        </div>
        <div style="left:6%; top:73%; height: 15%">
            <input type="submit" style="margin-left:5%; width:100%;height:100%">
        </div>
    </form>
      <div style="left:6%; top:99%; height: 15%">
          <?php
          session_start();
          if (isset($_SESSION["pastDateWarning"]) && $_SESSION["pastDateWarning"] == 2) { //In case user left a field blank on previous entry
              echo "<p>Bitte keine Felder leer lassen!</p>"; //Notify user of blank blankFields
              $_SESSION["pastDateWarning"] = 0; //Clear session id
          }
          ?>
      </div>
  </div>
 </body>
</html>