
<html>
  <head>
    <title>Corewar</title>
  </head>
  <body>
    <p>
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
        echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\">Champ are figthing </p>";
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
