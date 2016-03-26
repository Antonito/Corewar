
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
	//echo $res;
	$tabb = explode("Le joueur", $res);
	$win = $tabb[count($tabb) - 1];
	var_dump($win);
	if (strpos($_POST['champ'][0], $_SESSION['login']) == true)
	{
		$dbhost = 'localhost:3306';
   		$dbuser = 'root';
   		$dbpass = 'tekdoom';
		$dbname = 'tekdoom';
   		$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
   		if(! $conn )
   		{
     			die('Could not connect: ' . mysql_error());
   		}
		if ($win[1] == '1')
		{
			$sql = "UPDATE player SET score = score + 10, victoire = victoire + 1 WHERE login LIKE '".$_SESSION['login'] . "'";
			if (mysqli_query($conn, $sql)) {
    				echo "Record updated successfully";
			} else {
    				echo "Error updating record: " . mysqli_error($conn);
			}
		}
		else
		{
			$sql = "UPDATE player SET score = score - 10, defaite = defaite + 1 WHERE login LIKE '".$_SESSION['login'] . "'";
			if (mysqli_query($conn, $sql)) {
    				echo "Record updated successfully";
			} else {
    				echo "";
			}
		}
   		mysqli_close($conn);
	}
      ?>
    </p>
  </body>
</html>
