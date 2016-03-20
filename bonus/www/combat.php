
<html>
  <head>
    <title>My First Array</title>
  </head>
  <body>
    <p>
      <?php
	ini_set('display_errors', 'On');
	error_reporting(E_ALL);
	session_start();
	if (isset($_SESSION["login"]))
	{
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
	echo "<br>Champs are fighting, Poc est un caca <3<br>";
	$dir = "/home/tekdoom/CPE_2015_corewar/bonus/www/";
	$all_champ = "";
	foreach ($_POST['champ'] as $selectedOption)
		{
		    $all_champ .= '"' .$selectedOption . '"' . " ";
		}
	echo "<br>";
	$res = shell_exec($dir."corewar ".$all_champ . " 2>&1");
	echo $res;
      ?>
    </p>
  </body>
</html>
