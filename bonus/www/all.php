
<html>
  <head>
    <title>Corewar</title>
  </head>
  <body>
    <p style="background-color:rgba(255,255,255,0.5);">
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}
        echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\"> Select champions for the WAR !!</p>";
	$dir = "/home/tekdoom/CPE_2015_corewar/bonus/www/bd/";
	$files = scandir($dir); 
	echo "<br>";
	echo "<form action='combat.php' method='post'>";
	echo '<select name="champ[]" multiple="multiple">';
	$res = scandir($dir.$_SESSION['login']);
	$user_file = $res[2]; 
	echo "<option value='" .$dir.$_SESSION['login']. "/".$user_file . "'>".$_SESSION['login']."/".$user_file."</option>";
	foreach($files as $file)
	{
		if(is_file($dir.$file)){
			echo "<option value='" . $dir.$file . "'>".$file."</option>";
		}
	}
	echo "</select>";
	echo "<input type='submit' value='launch the VM'>";
	echo "</form>";
      ?>
    </p>
  </body>
</html>
