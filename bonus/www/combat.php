
<html>
  <head>
    <title>Corewar</title>
  </head>
  <body>
	<img class="leek_left" src="imgs/leek_left.png" alt="leek_left">
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
	$dir = "/home/tekdoom/CPE_2015_corewar/bonus/www/";
	$all_champ = "";
	$irlplayer = array("");
	foreach ($_POST['champ'] as $selectedOption)
		{
		    $all_champ .= '"' .$selectedOption . '"' . " ";
			if (strpos($selectedOption, "_") == true)
			{
				$rawlogin = explode('/', $selectedOption);
				array_push($irlplayer, $rawlogin[count($rawlogin) - 2]);
			}
		}
	echo "<br>";
	$res = shell_exec($dir."corewar ".$all_champ . " 2>&1");
	echo "<p class='resultat'> " .$res. "</p>";
	$tabb = explode("Le joueur", $res);
	$win = $tabb[count($tabb) - 1];
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
    				echo "";
			} else {
    				echo "";
			}
			foreach($irlplayer as $player)
			{
				echo " ". $player . " ";
				$sql = "UPDATE player SET score = score - 10, defaite = defaite + 1 WHERE login LIKE '".$player. "' AND login NOT LIKE '" . $_SESSION['login']."'";
				mysqli_query($conn, $sql);
			}
		}
		else
		{
			if (strpos($_POST['champ'][(int)$win[1] - 1], "_") == true)
			{
				echo "BITOUILLELLELELELELELE";
				$rawlogin = explode('/', $selectedOption);
				$winlog = $rawlogin[count($rawlogin) - 2];
				$sql = "UPDATE player SET score = score + 10, victoire = victoire + 1 WHERE login LIKE '".$winlog . "'";
				mysqli_query($conn, $sql);
				foreach($irlplayer as $player)
				{
					$sql = "UPDATE player SET score = score - 10, defaite = defaite + 1 WHERE login NOT LIKE '" . $winlog."' AND login LIKE'" . $player. "'";
					mysqli_query($conn, $sql);
				}
			}
			else
			{
				echo "BITEEEEEE";
				foreach($irlplayer as $player)
				{
					$sql = "UPDATE player SET score = score - 10, defaite = defaite + 1 WHERE login LIKE '" . $player ."'";
					mysqli_query($conn, $sql);
				}
			}
		}
   		mysqli_close($conn);
	}
      ?>
    </p>
	<img class="leek_right" src="imgs/leek_right.png" alt="leek_right">
  </body>
</html>
