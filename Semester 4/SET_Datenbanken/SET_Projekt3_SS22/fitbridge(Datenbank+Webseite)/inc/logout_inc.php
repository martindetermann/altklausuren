<?php
include("php_sql_inc.php");
/**
 * FitBridge
 *
 * This php script is called by an html button (user presses) to clear all session variables, and redirect to index
 *
 * @return 0 this function is too simple to have errors.
 *
 * @author  Ahmed Sabti, Martin Determann, Bland Azad Saleem, Othmane Kribia
 * @license Only to be used by Fitness24 as permitted by contract [LINK TO CONTRACT]
 */

  session_start(); //To access session variables
  session_regenerate_id(); //To invalidate old session id
  session_destroy(); //To destroy old session ids
  echo "Sie wurden ausgeloggt!"; //Notify user
  //In case pop ups are disabled prints error message:
  include 'popupwarning_inc.php';
  echo "<a href='../index.html'>oder clicke hier um weiter zu gehen</a>"; //link to index
  header("Location: ../index.html");
  exit();
  return 0;
